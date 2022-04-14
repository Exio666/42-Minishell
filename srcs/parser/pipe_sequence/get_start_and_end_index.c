/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_and_end_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:59:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:36:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_start_index_pipe_sequence(char *user_input, int pipe_sequence_to_find)
{
	int	start_index;
	int	current_pipe_seq;

	start_index = 0;
	current_pipe_seq = 0;
	while (user_input[start_index] && current_pipe_seq < pipe_sequence_to_find)
	{
		if (is_log_op(user_input, start_index))
		{
			start_index += 2;
			current_pipe_seq++;
			while (is_space(user_input[start_index]))
				start_index++;
		}
		else
			start_index++;
	}	
	return (start_index);
}

int	get_end_index_pipe_sequence(char	*user_input, int start_index)
{
	int	i;

	i = start_index;
	while (user_input[i] && !is_log_op(user_input, i))
		i++;
	return (i - 1);
}

int	is_log_op(char *user_input, int i)
{
	int	logical_op;

	if (is_logical_op_char(user_input[i]))
	{
		logical_op = get_logic_op_from_begin(user_input, i);
		if (logical_op_type_is_found(logical_op))
			return (TRUE);
	}
	return (FALSE);
}