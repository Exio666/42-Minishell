/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:40:00 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 13:19:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_is_flag_echo(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
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
	while (i < ac && arg_is_flag_echo(argv[i]))
	{
		flag_n = 1;
		i++;
	}
	while (i < ac)
	{
		ft_putstr_fd(argv[i], 1);
		if (i < ac - 1)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (flag_n == 0)
		write(1, "\n", 1);
	return (0);
}
