/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 14:18:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_tree(t_btree *root, t_lst_env **env_list)
{
	if (!root)
		return ;
	execute_command_tree(root->left, env_list);
	if (root->token)
		execute_command(root->token, env_list);
	execute_command_tree(root->right, env_list);
}

int	exec_one_cmd(char **argv, t_lst_env **env_list)
{
	int	retour;
	int	pid;

	retour = exec_builtins(len_av(argv), argv, env_list);
	if (retour == 127)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, &handler_sigint_empty);
			execute(argv, env_list);
			__ft_calloc(-1);
			exit(127);
		}
		while (waitpid(-1, NULL, 0) > 0)
			;
	}
	return (retour);
}
void print_token_list(t_lst_token *token)
{
	while (token)
	{
		printf("%d | [%s]  ->  ", token->type, token->str);
		token = token->next;
	}
	printf("NULL\n");
}

void	execute_command(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	int		count;

	count = count_pipe(token);
		print_token_list(token);
	expand_command(token, *env_list);
	if (count == 1)
	{
//		tokenisation_post_expand(token);
		print_token_list(token);
		set_up_redirect_in(token);
		set_up_redirect_out(token);
		argv = create_argv_cmd(token);
		exec_one_cmd(argv, env_list);
	}
	else
		exec_pipe_cmd(token, env_list, count);
}

void	execute_here_doc_tree(t_btree *root);
