/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_pipe_sequence_in_tree.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:09:25 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/15 10:31:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_ALL_PIPE_SEQUENCE_IN_TREE_H
# define ADD_ALL_PIPE_SEQUENCE_IN_TREE_H

# include "minishell.h"

void			add_all_pipe_sequence_in_tree(t_btree **root, char *user_input);
t_pipe_sequence	**split_all_pipe_sequence(char *user_input);
void			remove_parenthesis(char *str);
int				count_pipe_sequence(char *user_input);
void print_pipe_seq_array(t_pipe_sequence **pip_seq);
#endif