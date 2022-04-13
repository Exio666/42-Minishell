/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_logical_op.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/12 15:23:25 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LOGICAL_OP_H
# define GET_LOGICAL_OP_H

# include "minishell.h"

/*----- get_logical_op.c -----*/

int	get_logic_op_from_end(char *user_input, int i);
int	get_logic_op_from_begin(char *user_input, int i);

#endif