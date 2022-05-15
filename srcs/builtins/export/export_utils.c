/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:14:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 15:14:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg_export(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] == '=' || !(ft_isalpha(arg[0])) || arg[i] == '_')
	{
		ft_putstr_fd("export: \'", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd("\' is not a valid identifier", 2);
		return (0);
	}
	while (arg[i] != '=' || i == 0)
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_' ))
		{
			ft_putstr_fd("export: \'", 2);
			ft_putstr_fd(arg, 2);
			ft_putendl_fd("\' is not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

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
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
