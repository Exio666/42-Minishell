/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/10 14:11:35 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_varr_env(char *name, char *varraible, t_lst_env **envp)
{
	t_lst_env	*end;
	t_lst_env	*new;

	end = *envp;
	new = __ft_calloc(sizeof(t_lst_env) * 1);
	while (end->next)
		end = end->next;
	new->name = name;
	new->content = ft_strdup(varraible);
	new->next = NULL;
	new->prev = end;
	end->next = new;
	return (0);
}

int	put_varraible(char *arg, t_lst_env **envp)
{
	char	*name;
	int		i;
	int		len;

	if (!arg || !str_conctent_car(arg, '='))
		return (0);
	len = ft_strlen_stop_car(arg, '=');
	if (len == 0)
		return (1);
	name = __ft_calloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
	delete_varraible(name, envp);
	add_varr_env(name, &arg[len + 1], envp);
	return (0);
}

int	ft_export(int ac, char **arg, t_lst_env **envp)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		//if (check_arg_export(arg[i]))
			put_varraible(arg[i], envp);
		i++;
	}
	return (0);
}
