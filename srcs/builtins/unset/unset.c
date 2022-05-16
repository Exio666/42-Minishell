/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:33:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 17:41:38 by rpottier         ###   ########.fr       */
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

int	delete_variable(char *name, t_lst_env **envp)
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

int	check_arg_unset(char *arg)
{
	int	i;

	i = 1;
	if (!(ft_isalpha(arg[0])) || arg[i] == '_')
	{
		ft_putstr_fd("unset: \'", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd("\' is not a valid identifier", 2);
		return (0);
	}
	while (arg[i])
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_' ))
		{
			ft_putstr_fd("unset: \'", 2);
			ft_putstr_fd(arg, 2);
			ft_putendl_fd("\' is not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_unset(int ac, char **arg, t_lst_env **envp)
{
	int	i;
	int	retour;

	i = 1;
	retour = 0;
	while (i < ac)
	{
		if (check_arg_unset(arg[i]))
			delete_variable(arg[i], envp);
		else
			retour = 1;
		i++;
	}
	return (retour);
}
