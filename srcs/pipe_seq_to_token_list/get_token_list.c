/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:48:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 15:41:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token *get_token_list(char	*pipe_sequence)
{
	char	**split;
	t_lst_token 	*token_lst;
	
	split = split_by_separator(pipe_sequence, "|<>");
	token_lst = create_token_list(split);
	return (token_lst);
}

void	add_token_list_in_tree(t_btree **root, t_list *token)
{
		
}
