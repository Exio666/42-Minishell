/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:19:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 09:10:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_size(t_lst_env *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

char	**env_list_to_tab(t_lst_env **list_env)
{
	t_lst_env	*list;
	char		**tab;
	char		*tmp;
	int			index;

	index = 0;
	list = *list_env;
	if (!list)
		return (NULL);
	tab = __ft_calloc(sizeof(char *) * (env_lst_size(list) + 1));
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
