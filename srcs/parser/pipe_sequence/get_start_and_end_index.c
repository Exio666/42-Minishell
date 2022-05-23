/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_and_end_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:59:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 10:16:04 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"





int	get_start_index_pipe_sequence(char *user_input, int pipe_sequence_to_find)
{
	int	start_index;
	int	current_pipe_seq;
	int len;

	len = 0;
	start_index = 0;
	current_pipe_seq = 0;
	if (user_input)
		len = ft_strlen(user_input);
	else
		return (start_index);
	while (start_index < len && current_pipe_seq < pipe_sequence_to_find)
	{
		pipe_skip_quote(user_input, &start_index);
		if (is_log_op(user_input, start_index))
		{
			start_index += 2;
			current_pipe_seq++;
			while (start_index < len
				&& is_white_space(user_input[start_index]))
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
	int len;

	len = 0;
	i = start_index;
	if (user_input)
		len = ft_strlen(user_input);
	else
		return (0);
	while (i < len && !is_log_op(user_input, i))
	{
		if (is_quote(user_input[i]))
			pipe_skip_quote(user_input, &i);
		else
			i++;
	}
	return (i - 1);
}

void	pipe_skip_quote(char *str, int *index)
{
	if (str && *index < (int)ft_strlen(str))
	{
		if (str[(*index)] && (is_simple_quote(str[(*index)])
				|| is_double_quote(str[(*index)])))
		{
			if (is_simple_quote(str[(*index)]))
			{
				(*index)++;
				while (str[(*index)] && *index
					&& !is_simple_quote(str[(*index)]))
					(*index)++;
				if (str[(*index)] && str[(*index) + 1] != '\0')
					(*index)++;
			}
			else if (is_double_quote(str[(*index)]))
			{
				(*index)++;
				while (str[(*index)] && *index
					&& !is_double_quote(str[(*index)]))
					(*index)++;
				if (str[(*index)] && str[(*index) + 1] != '\0')
					(*index)++;
			}
		}
	}
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
