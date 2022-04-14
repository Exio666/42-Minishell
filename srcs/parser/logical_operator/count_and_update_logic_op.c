/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_update_logic_op.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:45:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 17:14:30 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_logical_op(t_logic_op *logical_op, int position, int cur_log_op)
{	
	logical_op->index = position;
	logical_op->type = cur_log_op;
	if (cur_log_op == AND_OPERATOR)
	{
		logical_op->symbol[0] = '&';
		logical_op->symbol[1] = '&';
	}
	else if (cur_log_op == OR_OPERATOR)
	{
		logical_op->symbol[0] = '|';
		logical_op->symbol[1] = '|';
	}
}

int	count_logic_op(char *user_input)
{	
	int	actual_logical_op;
	int	logical_op_count;
	int	i;

	if (user_input == NULL)
		return (-1);
	i = 0;
	logical_op_count = 0;
	while (user_input[i + 1])
	{
		skip_quote(user_input, &i);
		if (user_input[i + 1] && is_logical_op_char(user_input[i]) == TRUE)
		{
			actual_logical_op = get_logic_op_from_begin(user_input, i);
			if (actual_logical_op != OPERATOR_NOT_FOUND)
				logical_op_count++;
			i++;
		}
		i++;
	}
	return (logical_op_count);
}
