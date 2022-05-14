/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 19:39:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token	*create_token_list(char **split)
{
	int			i;
	int			j;
	char		**space_split;
	t_lst_token	*lst;

	lst = NULL;
	i = 0;
	while (split[i])
	{
		space_split = split_pipe_by_space(split[i]);
		j = 0;
		while (space_split[j])
		{
			ft_lstadd_back_token(&lst, create_token(space_split[j]));
			j++;
		}
		i++;
	}
	return (lst);
}

t_lst_token	*ft_lstlast_token(t_lst_token *token)
{
	t_lst_token	*last;

	last = token;
	if (!last)
		return (token);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_lstadd_back_token(t_lst_token **alst, t_lst_token *new)
{
	t_lst_token	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_token(*alst);
	tmp->next = new;
}
