/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_update_logic_op.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:45:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/22 16:36:46 by rpottier         ###   ########.fr       */
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

int	skip_quote_and_confirm(char *user_input, int *i)
{
	skip_quote(user_input, i);
	return (TRUE);
}

int	count_logic_op(char *user_input)
{	
	int	logical_op_count;
	int	i;
	int	quote_skiped;

	if (user_input == NULL)
		return (-1);
	i = 0;
	logical_op_count = 0;
	while (i >= 0 && user_input[i] && user_input[i + 1])
	{
		quote_skiped = FALSE;
		if (is_quote(user_input[i]))
			quote_skiped = skip_quote_and_confirm(user_input, &i);
		if (i >= 0 && user_input[i] && user_input[i + 1]
			&& is_logical_op_char(user_input[i]))
		{
			if (get_logic_op_from_begin(user_input, i) != OPERATOR_NOT_FOUND)
				logical_op_count++;
			i++;
		}
		if (i >= 0 && !quote_skiped)
			i++;
	}
	return (logical_op_count);
}
