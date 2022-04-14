/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_btree_of_logical_op.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:17:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 10:48:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_BTREE_OF_LOGICAL_OP_H
# define GET_BTREE_OF_LOGICAL_OP_H

# include "minishell.h"

/*----- get_btree_of_logical_op.c ------*/

t_btree	*get_btree_of_logical_op(char *user_input);

#endif