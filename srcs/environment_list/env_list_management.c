/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:56:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 17:07:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_tab_to_list.h"

t_lst_env	*create_list_env_elem(char *variable_env)
{
	t_lst_env	*list_elem;

	list_elem = __ft_calloc(sizeof(t_lst_env));
	list_elem->name = get_variable_name(variable_env);
	list_elem->content = get_variable_content(variable_env);
	list_elem->next = NULL;
	list_elem->prev = NULL;
	return (list_elem);
}

void	ft_dlist_env_add_back(t_lst_env **alst, t_lst_env *new)
{
	t_lst_env	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_dlist_env_last(*alst);
	tmp->next = new;
	new->prev = tmp;
}

t_lst_env	*ft_dlist_env_last(t_lst_env	*lst)
{
	t_lst_env	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
