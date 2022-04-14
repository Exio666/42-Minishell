/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 13:38:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree	*btree_create_node_logic_op(void *item)
{
	t_btree	*new;

	new = __ft_calloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->logic_op = item;
	new->pipe_seq = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_btree	*btree_create_node_pipe_seq(void *item)
{
	t_btree	*new;

	new = __ft_calloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->logic_op = NULL;
	new->pipe_seq = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
