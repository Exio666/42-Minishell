/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/03 18:49:12 by bsavinel         ###   ########.fr       */
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

// parcourir les commandes séparés par les pipes
void	execute_pipe_sequence(t_lst_token *token, t_lst_env **env_list)
{
	while (token)
	{
		execute_command(token, env_list);
		token = find_first_token_next_cmd(token);
	}
}

int exec_one_cmd(char **argv, t_lst_env **env_list)
{
	int	retour;
	int	pid;

	retour = exec_builtins(len_av(argv), argv, env_list);
	if (retour == 127)
	{
		pid = fork();
		if (pid == 0)
		{
			execute(argv, env_list);
			exit(127);
		}
		while (waitpid(-1, NULL, 0) > 0)
			;
	}
	return(retour);
}

void	execute_command(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	//int		status;
	int		count;
	
	//expand(token, *env_list);
	//tokenisation_post_expand(token);
	count = count_pipe(token);
	fprintf(stderr, "count = %d\n", count);
	if (count == 1)
	{
		ft_putstr_fd("exec solo :\n", 2);
		argv = create_argv_cmd(token);
		exec_one_cmd(argv, env_list);
	}
	else
	{
		ft_putstr_fd("exec pipe :\n", 2);
		exec_pipe_cmd(token, env_list, count);
	}
}

void	execute_here_doc_tree(t_btree *root);


/*	if (argv)
	{	
		printf("-----------------\n");
		printf("argv_arg:\n");
		print_char_two_dim_array(argv);
		printf("-----------------\n");
	}
*/
/*int pid = fork();
	if (pid == 0)
	{
		set_up_redirect_in(token);
		set_up_redirect_out(token);
		execute(argv, env_list);
		exit(0);
	}
	else
		wait(&status);*/