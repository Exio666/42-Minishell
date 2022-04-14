/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:40:00 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 10:45:49 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_is_flag_echo(char *arg)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(int ac, char **argv)
{
	int	i;
	int	flag_n;

	i = 1;
	flag_n = 0;
	while (i < ac && arg_is_flag_echo(argv[1]))
	{
		flag_n = 1;
		i++;
	}
	while (i < ac)
	{
		ft_putstr_fd(argv[i], 1);
		i++;
	}
	if (flag_n == 0)
		write(1, "\n", 1);
	return (1);
}
