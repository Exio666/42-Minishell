/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_btree_of_logical_op.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:56:03 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/05 12:59:02 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree	*get_btree_of_logical_op(char *user_input)
{
	t_logic_op		**logical_op;
	t_input_level	*input_level;
	t_btree			*logical_op_in_btree;

printf("temoin 0\n");
	input_level = attribute_level(user_input);

printf("temoin 1\n");
//	printab_input_level(input_level);
	logical_op = create_logical_op_array(user_input);

printf("temoin 2\n");
	logical_op_in_btree = parse_op_by_level(logical_op, input_level);

printf("temoin 3\n");
	if (!logical_op_in_btree)
		return (NULL);
	return (logical_op_in_btree);
}
