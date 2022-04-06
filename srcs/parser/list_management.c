/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:48 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/06 15:50:29 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*lstlast(t_list *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

t_list	*lstnew(void *elem)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = elem;
	new_elem->next = NULL;
	return (new_elem);
}

void	lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = lstlast(*alst);
		tmp->next = new;
	}
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	free(tmp);
}
