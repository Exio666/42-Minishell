/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:47 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 14:17:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_MANAGEMENT_H
# define BTREE_MANAGEMENT_H

# include "minishell.h"

/*----- btree_management.c -----*/

void	insert_logic_op(t_btree	**btree, int actual_op_index,
			t_logic_op **logical_op);

int		cmp_index_logical_op(UI actual_op_index, UI index_node);

void	btree_insert_log_op(t_btree **root, t_logic_op *logical_op,
			int (*cmpf)(UI, UI));

t_btree	*btree_create_node(void *item);
void	*set_to_null(void);

#endif