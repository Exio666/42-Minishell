/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operator_indexation.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:37 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 19:53:14 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICAL_OPERATOR_IINDEXATION_H
# define LOGICAL_OPERATOR_IINDEXATION_H

/*----- logical_operator_indexation.c -----*/

t_logic_op	*get_current_log_op(int actual_op_index, t_logic_op **logical_op);
t_logic_op	**malloc_logical_op_reference(char *user_input);
t_logic_op	**create_logical_op_array(char *user_input);

#endif