/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:27:40 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/21 17:22:13 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	t_btree	*item;

	item = NULL;
	if (root == NULL || data_ref == NULL)
		return (NULL);
	if (root->left)
		item = btree_search_item(root->left, data_ref, cmpf);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->right)
		item = btree_search_item(root->right, data_ref, cmpf);
	return (item);
}