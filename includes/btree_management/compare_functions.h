/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_functions.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:41:39 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:42:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_FUNCTIONS_H
# define COMPARE_FUNCTIONS_H

# include "minishell.h"

int	cmp_index_logical_op(unsigned int actual_op_index, unsigned int index_node);
int	cmp_index_pipe_seq(unsigned int actual_op_index, unsigned int index_node);

#endif