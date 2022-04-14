/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_functions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:41:32 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:41:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_NODE_FUNCTIONS_H
# define CREATE_NODE_FUNCTIONS_H

# include "minishell.h"

t_btree	*btree_create_node_logic_op(void *item);
t_btree	*btree_create_node_pipe_seq(void *item);

#endif