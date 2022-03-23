/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:31:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/21 11:36:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	int cmp;

	cmp = cmpf(root->item, item);
	if (cmp < 0)
	{
		if (!root->left)
			root->left = btree_create_node(item);
		else
			btree_insert_data(root->left, item, &cmpf);
	}
	else
	{
		if (!root->right)
			root->right = btree_create_node(item);
		else
			btree_insert_data(root->right, item, &cmpf);
	}
}