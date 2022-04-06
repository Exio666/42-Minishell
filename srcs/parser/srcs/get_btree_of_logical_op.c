/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_btree_of_logical_op.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:56:03 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/06 15:00:15 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_btree	*get_btree_of_logical_op(char *user_input)
{
	t_logic_op		**logical_op;
	t_input_level	*input_level;
	t_btree			*logical_op_in_btree;

	input_level = attribute_level(user_input);
	logical_op = create_logical_op_array(user_input);
	logical_op_in_btree = parse_op_by_level(logical_op, input_level);
	if (!logical_op_in_btree)
		return (NULL);
	return (logical_op_in_btree);
}
