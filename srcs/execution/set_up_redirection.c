/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:47:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/12 11:50:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_out(t_lst_token *token, int child)
{
	int	fd_file;

	token = token->next;
	if (token)
	{
		fd_file = open(token->str, O_WRONLY | O_CREAT, 00777);
		if (fd_file == -1)
			return (open_failed(token->str, child));
		if (dup2(fd_file, STDOUT_FILENO) == -1)
			return (open_failed(token->str, child));
		close(fd_file);
	}
	return (0);
}

int	redirect_out_append(t_lst_token *token, int child)
{
	int	fd_file;

	token = token->next;
	if (token)
	{
		fd_file = open(token->str, O_WRONLY | O_CREAT | O_APPEND, 00777);
		if (fd_file == -1)
			return (open_failed(token->str, child));
		if (dup2(fd_file, STDOUT_FILENO) == -1)
			return (open_failed(token->str, child));
		close(fd_file);
	}
	return (0);
}

int	redirect_in(t_lst_token *token, int child)
{
	int	fd_file;

	token = token->next;
	if (token)
	{
		fd_file = open(token->str, O_RDONLY);
		if (fd_file == -1)
			return (open_failed(token->str, child));
		if (dup2(fd_file, STDIN_FILENO) == -1)
		{
			close(fd_file);
			return (open_failed(token->str, child));
		}
		close(fd_file);
	}
	token = token->next;
	return (0);
}

int	redirect_in_heredoc(t_lst_token *token, int child)
{
	int	fd_file;

	token = token->next;
	if (token)
	{
		fd_file = open(token->str, O_RDONLY);
		if (fd_file == -1)
			return (open_failed(token->str, child));
		if (dup2(fd_file, STDIN_FILENO) == -1)
		{
			unlink(token->str);
			close(fd_file);
			return (open_failed(token->str, child));
		}
		unlink(token->str);
		close(fd_file);
	}
	token = token->next;
	return (0);
}

int	set_up_redirect(t_lst_token *token, int child)
{
	while (token && token->type != TOK_PIPE)
	{
		if (token && token->type == TOK_REDIRECT_OUT)
			if (redirect_out(token, child))
				return (1);
		if (token && token->type == TOK_REDIRECT_OUT_APPEND)
			if (redirect_out_append(token, child))
				return (1);
		if (token && token->type == TOK_REDIRECT_IN)
			if (redirect_in(token, child))
				return (1);
		if (token && token->type == TOK_HEREDOC)
			if (redirect_in_heredoc(token, child))
				return (1);
		token = token->next;
	}
	return (0);
}
