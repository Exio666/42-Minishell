/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:47:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/30 22:27:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
			fd_file = open(token->str, O_WRONLY | O_CREAT, 00777);
			dup2(fd_file, STDOUT_FILENO);
		//	close(fd_file);
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
			//close(fd_file);
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
			fd_file = open(token->str, O_CREAT | O_APPEND);
			dup2(fd_file, STDOUT_FILENO);
			close(fd_file);
		}
	}
}
