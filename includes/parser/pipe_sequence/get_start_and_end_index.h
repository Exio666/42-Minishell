/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_and_end_index.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:08:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 14:26:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_START_AND_END_INDEX_H
# define GET_START_AND_END_INDEX_H

# include "minishell.h"

int		get_start_index_pipe_sequence(char *user_input,
			int pipe_sequence_to_find);
int		get_end_index_pipe_sequence(char	*user_input, int start_index);
int		is_log_op(char *user_input, int i);
void	pipe_skip_quote(char *str, int *index);
#endif