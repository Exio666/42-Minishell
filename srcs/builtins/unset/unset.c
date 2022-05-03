/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:33:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/02 16:49:22 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	*find_element_with_name(char *name, t_lst_env **envp)
{
	t_lst_env	*tmp;

	tmp = *envp;
	while (tmp && ft_strcmp(tmp->name, name) != 0)
		tmp = tmp->next;
	return (tmp);
}

void	delete_varraible(char *name, t_lst_env **envp)
{
	t_lst_env	*elem;
	t_lst_env	*prev;
	t_lst_env	*next;

	elem = find_element_with_name(name, envp);
	if (!elem)
		return (0);
	prev = elem->prev;
	next = elem->next;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
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
