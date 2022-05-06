/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:33:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/03 16:42:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	*find_element_with_name(char *name, t_lst_env **envp)
{
	t_lst_env	*tmp;

	tmp = *envp;
	while (tmp && ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) != 0)
		tmp = tmp->next;
	return (tmp);
}

int	delete_varraible(char *name, t_lst_env **envp)
{
	t_lst_env	*elem;
	t_lst_env	*prev;
	t_lst_env	*next;

	elem = find_element_with_name(name, envp);
	if (!elem)
		return (1);
	prev = elem->prev;
	next = elem->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	return (0);
}

int	ft_unset(int ac, char **arg, t_lst_env **envp)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		delete_varraible(arg[i], envp);
		i++;
	}
	return (0);
}
