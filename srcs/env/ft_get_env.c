/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:50:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 16:30:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_env_var(t_lst_env *lst)
{
	char	*varriable;

	varriable = ft_strjoin(list->name, "=");
	if (!tmp)
		return (NULL);
	varriable = ft_strjoin(varriable, list->content);
}

char	*ft_get_env(t_lst_env **env_list, char *name)
{	
	t_lst_env	*tmp;

	tmp = *env_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(name)) == 0)
			return (join_env_var(tmp));
		tmp = tmp->next;
	}
	return (NULL);
}
