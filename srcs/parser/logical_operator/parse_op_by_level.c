/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_by_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:41:57 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 20:22:28 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree	*parse_op_by_level(t_logic_op **logical_op, t_input_level *input_level)
{
	t_btree			*btree;
	t_prio_level	level;
	t_logic_op		cur_op;
	int				i;

	init_level(&level, input_level);
	btree = NULL;
	while (priority_levels_remaining(level.current, level.max))
	{
		i = ft_strlen(input_level->input) - 1;
		while (actual_level_not_fully_checked(i))
		{
			if (is_part_of_current_level(input_level->level[i], level.current)
				&& is_logical_op_char(input_level->input[i]))
			{
				cur_op.type = get_logic_op_from_end(input_level->input, i);
				if (logical_op_type_is_found(cur_op.type))
					insert_all_logic_op_in_tree(&btree, i - 1, logical_op);
				i--;
			}
			i--;
		}
		increase_level(&level.current);
	}
	return (btree);
}

int	priority_levels_remaining(int actual_level, int level_max)
{
	if (actual_level <= level_max)
		return (1);
	else
		return (0);
}

int	actual_level_not_fully_checked(int i)
{
	if (i >= 0)
		return (1);
	else
		return (0);
}

int	is_part_of_current_level(int char_level, int actual_level)
{
	if (char_level == actual_level)
		return (1);
	else
		return (0);
}

int	logical_op_type_is_found(int logical_op_type)
{
	if (logical_op_type == OPERATOR_NOT_FOUND)
		return (0);
	return (1);
}
