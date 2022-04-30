/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/30 17:23:49 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_tree(t_btree *root, t_lst_env *env_list)
{
	if (!root)
		return ;
	execute_command_tree(root->left, env_list);
	if (root->token)
		execute_pipe_sequence(root->token, env_list);
	execute_command_tree(root->right, env_list);
}

// parcourir les commandes séparés par les pipes
void	execute_pipe_sequence(t_lst_token *token, t_lst_env *env_list)
{
	while (token)
	{
		execute_command(token, env_list);
		token = find_first_token_next_cmd(token);
	}
}

/* REDIRECT_IN */

void	set_up_redirect_out(t_lst_token *token)
{
	int	fd_file;

	while (token && token->type != TOK_REDIRECT_OUT)
	{
		token = token->next;
	}
	if (token && token->type == TOK_REDIRECT_OUT)
	{
		token = token->next;
		if (token)
		{
			fd_file = open(token->str, O_CREAT, O_RDWR);
			dup2(fd_file, STDOUT_FILENO);
			close(fd_file);
		}
	}
}

void	set_up_redirect_in(t_lst_token *token)
{
	int	fd_file;

	while (token && token->type != TOK_REDIRECT_IN)
	{
		token = token->next;
	}
	if (token && token->type == TOK_REDIRECT_IN)
	{
		token = token->next;
		if (token)
		{
			fd_file = open(token->str, O_RDONLY);
			dup2(fd_file, STDIN_FILENO);
			close(fd_file);
		}
	}
}

void	set_up_redirect_out_append(t_lst_token *token)
{
	int	fd_file;

	while (token && token->type != TOK_REDIRECT_OUT_APPEND)
	{
		token = token->next;
	}
	if (token && token->type == TOK_REDIRECT_OUT_APPEND)
	{
		token = token->next;
		if (token)
		{
			fd_file = open(token->str, O_CREAT, O_APPEND);
			dup2(fd_file, STDOUT_FILENO);
			close(fd_file);
		}
	}
}

void	execute_command(t_lst_token *token, t_lst_env *env_list)
{
	char	**argv;
	int status;
	expand(token, env_list);
	tokenisation_post_expand(token);
	argv = create_argv_cmd(token);
/*	if (argv)
	{	
		printf("-----------------\n");
		printf("argv_arg:\n");
		print_char_two_dim_array(argv);
		printf("-----------------\n");
	}
*/

	int pid = fork();
	if (pid == 0)
	{
		set_up_redirect_in(token);
		set_up_redirect_out(token);
		set_up_redirect_out_append(token);
		execute(argv, env_list);
		exit(0);
	}
	else
		wait(&status);
}
