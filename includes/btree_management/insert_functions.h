/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:34:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 12:27:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_FUNCTIONS_H
# define INSERT_FUNCTIONS_H

# include "minishell.h"

void	insert_all_logic_op_in_tree(t_btree	**root, int curr_op_index,
			t_logic_op **logic_op);
void	insert_all_pipe_seq_in_btree(t_btree **root,
			t_pipe_sequence **splited_pipe_seq);

void	btree_insert_log_op(t_btree **root, t_logic_op *logic_op,
			int (*cmpf)(UI, UI));
void	btree_insert_pipe_seq(t_btree **root, t_pipe_sequence *pipe_seq,
			int (*cmpf)(UI, UI));

#endif