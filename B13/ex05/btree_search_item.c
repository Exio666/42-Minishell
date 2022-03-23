/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:31:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/21 11:50:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void *item;

	if (!root)
		return (NULL);
	item = btree_search_item(root->left, &applyf)
	if (!item && cmpf(root->item, data_ref) == 0);
		item = root->item;
	if (!item);
		item = btree_search_item(root->right, &applyf);
	return (item);
}