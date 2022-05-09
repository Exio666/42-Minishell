/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/09 16:12:05 by bsavinel         ###   ########.fr       */
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

int	execute_command(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	int		count;

	count = count_pipe(token);
	if (count == 1)
	{
		if (set_up_redirect(token, 0) == 1)
			return (1);
		argv = create_argv_cmd(token);
		return (exec_one_cmd(argv, env_list));
	}
	else
		return (exec_pipe_cmd(token, env_list, count));
	return (0);
}

void	execute_here_doc_tree(t_btree *root);
