/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:49:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 20:15:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*set_to_null(void)
{
	return (NULL);
}

void	insert_logic_op(t_btree	**bt, int curr_op_index, t_logic_op **logic_op)
{
	t_logic_op	*current_log_op;

	current_log_op = get_current_log_op(curr_op_index, logic_op);
	btree_insert_log_op(bt, current_log_op, cmp_index_logical_op);
}

void	btree_insert_log_op(t_btree **root, t_logic_op *logic_op,
	int (*cmpf)(UI, UI))
{
	if (*root == NULL)
		*root = btree_create_node(logic_op);
	else if ((*cmpf)(logic_op->index, (*root)->item->index) < 0)
		btree_insert_log_op(&(*root)->left, logic_op, cmpf);
	else
		btree_insert_log_op(&(*root)->right, logic_op, cmpf);
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = __ft_calloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->item = item;
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
