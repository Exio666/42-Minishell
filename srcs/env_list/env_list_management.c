/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:56:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/05 17:38:36 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	*create_list_env_elem(char *variable_env)
{
	t_lst_env	*list_elem;
	int			tmp;

	list_elem = __ft_calloc(sizeof(t_lst_env));
	list_elem->name = get_variable_name(variable_env);
	if (ft_strncmp(list_elem->name, "SHLVL", 6) == 0)
	{
		tmp = ft_atoi(get_variable_content(variable_env));
		list_elem->content = ft_itoa(tmp + 1);
	}
	else
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

void	print_lst_env(t_lst_env	*list_elem)
{
	while (list_elem)
	{
		printf("%s = %s\n", list_elem->name, list_elem->content);
		list_elem = list_elem->next;
	}
}

void	free_t_lst_env(t_lst_env	*list_elem)
{
	t_lst_env	*list_tmp;

	while (list_elem)
	{
		list_tmp = list_elem;
		list_elem = list_elem->next;
		free(list_tmp->content);
		free(list_tmp->name);
		free(list_tmp);
	}
}
