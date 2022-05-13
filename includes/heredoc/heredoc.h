/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:25:18 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 17:54:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "minishell.h"
# include "destruct_heredoc.h"
# include "create_all_heredoc.h"

int		change_name_heredoc(char *str);
void	feed_herdoc(int fd, char *end);
char	*heredoc_create(char *end);

#endif