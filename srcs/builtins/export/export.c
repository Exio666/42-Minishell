/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/02 16:41:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_stop_car(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	str_conctent_car(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	add_varr_env(char *name, char *varraible, t_lst_env **envp)
{
	t_lst_env	*end;
	t_lst_env	*new;

	end = *envp;
	while (end->next)
		end = end->next;
	new->name = name;
	new->content = ft_strdup(varraible);
	new->next = NULL;
	new->prev = end;
	end->next = new;
	return (0);
}

char *put_varraible(char *arg, t_lst_env **envp)
{
	char	*name;
	char	*variable_env;
	int		i;
	int		len;

	if (!arg || str_conctent_car(arg, '='))
		return (1);
	len = ft_strlen_stop_car(arg, '=');
	name = __ft_calloc(sizeof(char), len + 1);
	i = 0;
	while (i < len)
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
	ft_unset(name, envp);
	add_varr_env(name, &arg[len], envp);
	return (0);
}

int	ft_export(int ac, char **arg, t_lst_env **envp)
{
	int i;

	i = 1;
	if (!arg)
		return (1);
	while (i < ac)
	{
		put_varraible(arg[i], envp);
		i++;
	}
	return (0);
}
