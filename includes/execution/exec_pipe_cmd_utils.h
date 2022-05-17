/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:26:23 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 08:26:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPE_CMD_UTILS_H
# define EXEC_PIPE_CMD_UTILS_H

# include "minishell.h"

int			init_pipe_fd(int pipe_stock[2], int new_pipe[2]);
void		multi_close(int fd_1, int fd_2, int fd_3, int fd_4);
void		failed_pipe(int pipe_stock[2], int new_pipe[2]);
t_lst_token	*move_to_next_pipe(t_lst_token *token);

#endif