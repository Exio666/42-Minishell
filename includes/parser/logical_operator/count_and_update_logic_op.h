/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_update_logic_op.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 14:32:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_AND_UPDATE_LOGIC_OP_H
# define COUNT_AND_UPDATE_LOGIC_OP_H

# include "minishell.h"

/*----- count_and_update_logic_op.c------*/

void	update_logical_op(t_logic_op *logical_op, int position,
			int actual_log_op);
int		count_logic_op(char *user_input);

#endif