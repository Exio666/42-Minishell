/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:25:18 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 08:31:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"
# include "destruct_heredoc.h"
# include "create_all_heredoc.h"

int		change_name_heredoc(char *str);
void	feed_heredoc(int fd, char *end);
void	exec_heredoc(int fd, char *end);
char	*fork_heredoc(int fd, char *end, char *str);
char	*heredoc_create(char *end);

#endif