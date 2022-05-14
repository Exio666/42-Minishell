/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operator_indexation.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:12:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 21:25:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICAL_OPERATOR_INDEXATION_H
# define LOGICAL_OPERATOR_INDEXATION_H

# include "minishell.h"

/*----- logical_operator_indexation.c -----*/

t_logic_op	*get_current_log_op(int actual_op_index, t_logic_op **logical_op);
t_logic_op	**malloc_logical_op_reference(char *user_input);
t_logic_op	**create_logical_op_array(char *user_input);
void		get_logical_op_and_skip(char *input, t_logic_op **logical_op,
				int *j, int *i);
#endif