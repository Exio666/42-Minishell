/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_sequence.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:12:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 16:23:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PIPE_SEQUENCE_H
# define GET_PIPE_SEQUENCE_H

#include "minishell.h"

typedef	struct s_pipe_sequence
{
	char			*str;
	unsigned int	index;
}	t_pipe_sequence;

void	btree_insert_pipe_sequence(t_btree **root, t_pipe_sequence *pipe_sequence, int (*cmpf)(UI, UI));
int		count_pipe_sequence(char *user_input);
int		get_pipe_sequence_end_index(char	*user_input, int start_index);
int		is_log_op(char *user_input, int i);
int		get_size_pipe_sequence(int start_index, int end_index);
char	*get_pipe_sequence(char	*user_input, int start_index);
int		get_start_index(char *user_input, int pipe_sequence_to_find);
char	**split_all_pipe_sequence(char *user_input);
void	insert_all_pipe_seq_in_btree(char *user_input);

#endif