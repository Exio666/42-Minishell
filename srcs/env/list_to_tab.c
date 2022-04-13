/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:19:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/11 15:42:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dlistsize(t_lst_env *lst)
{
	int			i;
	t_lst_env	*tmp;

	if (!lst)
		return (0);
	i = 1;
	tmp = lst->next;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**env_list_to_tab(t_lst_env **list_env)
{
	t_lst_env	*list;
	char		**tab;
	char		*tmp;
	int			index;

	index = 0;
	list = *list_env;
	tab = __ft_calloc(sizeof(char *) * (env_lst_size(list) + 1));
	if (!tab)
		return (NULL);
	while (list)
	{
		tmp = ft_strjoin(list->name, "=");
		if (!tmp)
			return (NULL);
		tab[index] = ft_strjoin(tmp, list->content);
		if (!tab[index])
			return (NULL);
		index++;
		list = list->next;
	}
	tab[index] = NULL;
	return (tab);
}
