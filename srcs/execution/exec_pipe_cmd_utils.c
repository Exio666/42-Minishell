/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:27:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 08:32:11 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multi_close(int fd_1, int fd_2, int fd_3, int fd_4)
{
	if (fd_1 != -1)
		close(fd_1);
	if (fd_2 != -1)
		close(fd_2);
	if (fd_3 != -1)
		close(fd_3);
	if (fd_4 != -1)
		close(fd_4);
}

int	init_pipe_fd(int pipe_stock[2], int new_pipe[2])
{
	pipe_stock[0] = -1;
	pipe_stock[1] = -1;
	new_pipe[0] = -1;
	new_pipe[1] = -1;
	return (0);
}

void	failed_pipe(int pipe_stock[2], int new_pipe[2])
{
	while (waitpid(-1, NULL, 0) > 0)
		;
	multi_close(pipe_stock[0], pipe_stock[1], new_pipe[0], new_pipe[1]);
	free_all();
	ft_putstr_fd("Fatal: pipe() failed\n", 2);
	exit(1);
}

t_lst_token	*move_to_next_pipe(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
		token = token->next;
	if (token && token->type == TOK_PIPE)
		token = token->next;
	return (token);
}
