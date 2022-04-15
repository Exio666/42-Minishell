/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:33:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/15 10:02:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_all_logic_op_in_tree(t_btree	**root, int curr_op_index,
			t_logic_op **logic_op)
{
	t_logic_op	*current_log_op;

	current_log_op = get_current_log_op(curr_op_index, logic_op);
	btree_insert_log_op(root, current_log_op, cmp_index_logical_op);
}

void	insert_all_pipe_seq_in_btree(t_btree **root,
			t_pipe_sequence **splited_pipe_seq)
{
	int		i;

	i = 0;
	while (splited_pipe_seq[i])
	{
		btree_insert_pipe_seq(root, splited_pipe_seq[i], cmp_index_pipe_seq);
		i++;
	}	
}

void	btree_insert_log_op(t_btree **root, t_logic_op *logic_op,
	int (*cmpf)(UI, UI))
{
	if (*root == NULL)
		*root = btree_create_node_logic_op(logic_op);
	else if ((*cmpf)(logic_op->index, (*root)->logic_op->index) < 0)
		btree_insert_log_op(&(*root)->left, logic_op, cmpf);
	else
		btree_insert_log_op(&(*root)->right, logic_op, cmpf);
}

void	btree_insert_pipe_seq(t_btree **root, t_pipe_sequence *pipe_seq,
	int (*cmpf)(UI, UI))
{
	if (*root == NULL)
		*root = btree_create_node_pipe_seq(pipe_seq);
	else if ((*cmpf)(pipe_seq->index, (*root)->logic_op->index) <= 0)
		btree_insert_pipe_seq(&(*root)->left, pipe_seq, cmpf);
	else
		btree_insert_pipe_seq(&(*root)->right, pipe_seq, cmpf);
}
