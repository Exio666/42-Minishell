/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:51:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/21 13:45:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

my_btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem), int level)
{
	if (!root)
		return ;
	if (level == 0)
		applyf(root->item, level, 1);
	else
		applyf(root->item, level, 0);
	my_btree_apply_by_level(root->left, &applyf, level + 1);
	my_btree_apply_by_level(root->right, &applyf, level + 1);
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int level;
	
	level = 0;
	applyf(root->item, )
	my_btree_apply_by_level(root, &applyf, level);
}