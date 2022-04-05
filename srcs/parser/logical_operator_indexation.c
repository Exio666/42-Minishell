/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operator_indexation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:18:50 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 17:03:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_logic_op	**malloc_logical_op_reference(char *input)
{
	t_logic_op	**logical_op;
	int			size;
	int			i;

	i = 0;
	if (input == NULL)
		return (NULL);
	size = count_logic_op(input);
	logical_op = calloc(size + 1, sizeof(t_logic_op *));
	if (logical_op == NULL)
		return (NULL);
	while (i < size)
	{
		logical_op[i] = calloc(1, sizeof(t_logic_op));
		if (logical_op[i] == NULL)
			return (NULL);
		i++;
	}
	return (logical_op);
}

t_logic_op	**create_logical_op_array(char *input)
{
	t_logic_op		**logical_op;
	int				actual_log_op;
	int				i;
	int				j;

	logical_op = malloc_logical_op_reference(input);
	if (logical_op == NULL)
		printf("FAIL 0\n");
	i = 0;
	j = 0;
	while (input[i] && input[i + 1])
	{
		if (input[i] && input[i + 1] && is_logical_op_char(input[i]) == TRUE)
		{
			actual_log_op = get_logic_op_from_begin(input, i);
			if (actual_log_op != OPERATOR_NOT_FOUND)
			{
				update_logical_op(logical_op[j], i, actual_log_op);
				j++;
			}
			i++;
		}
		i++;
	}
	return (logical_op);
}

t_logic_op	*get_current_log_op(int actual_op_index, t_logic_op **logical_op)
{
	int	i;

	i = 0;
	while (logical_op[i])
	{
		if (actual_op_index == logical_op[i]->index)
			return (logical_op[i]);
		i++;
	}
	return (NULL);
}
