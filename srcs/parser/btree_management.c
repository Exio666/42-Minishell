/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:49:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 21:42:04 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	*set_to_null(void)
{
	return (NULL);
}

void	insert_logic_op(t_btree	**bt, int curr_op_index, t_logic_op **logic_op)
{
	t_logic_op	*current_log_op;

	current_log_op = get_current_log_op(curr_op_index, logic_op);
	btree_insert(bt, current_log_op, cmp_index_logical_op);
}

void	btree_insert(t_btree **root, t_logic_op *logic_op, int (*cmpf)(UI, UI))
{
	if (*root == NULL)
		*root = btree_create_node(logic_op);
	else if ((*cmpf)(logic_op->index, (*root)->logic_op->index) < 0)
		btree_insert(&(*root)->left, logic_op, cmpf);
	else
		btree_insert(&(*root)->right, logic_op, cmpf);
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->logic_op = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	cmp_index_logical_op(unsigned int actual_op_index, unsigned int index_node)
{
	if (actual_op_index < index_node)
		return (-1);
	else
		return (1);
}