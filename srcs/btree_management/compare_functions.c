/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:44:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 13:44:30 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmp_index_logical_op(unsigned int actual_op_index, unsigned int index_node)
{
	if (actual_op_index < index_node)
		return (-1);
	else
		return (1);
}

int	cmp_index_pipe_seq(unsigned int actual_op_index, unsigned int index_node)
{
	if (actual_op_index < index_node)
		return (-1);
	else if (actual_op_index > index_node)
		return (1);
	else
		return (0);
}
