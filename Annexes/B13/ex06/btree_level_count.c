/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:51:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/23 12:53:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

my_btree_level_count(t_btree *root, int level)
{
	static int max_lvl;

	if (level == 0)
		max_lvl = 0;
	if (!root)
		return ;
	if (level > max_lvl)
		max_lvl++;
	my_btree_level_count(root->left, level + 1);
	my_btree_level_count(root->right, level + 1);
	return (max_lvl);
}

int btree_level_count(t_btree *root)
{
	int level;
	
	level = 0;
	return(my_btree_level_count(root, 0));
}
