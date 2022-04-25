/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:48:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/22 14:15:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *get_token_list(char	*pipe_sequence)
{
	char	**split;
	t_list 	*token_lst;
	
	split = split_by_separator(pipe_sequence, "|<>");
	token_lst = create_token_list(split);
	return (token_lst);
}

void	add_token_list_in_tree(t_btree **root, t_list *token_list)
{
		
}
