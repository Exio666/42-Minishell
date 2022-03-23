/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:00:22 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/21 11:14:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

#include <stdlib.h>

/*
 *	Structure
 */

typedef struct s_btree
{
	struct s_btree *left;
	struct s_btree *right;
	void *item;
}	t_btree;

#endif