/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:44:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 19:18:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_zeros(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	return (i);
}

int	good_arg_for_exit(char *arg)
{
	int	i;
	int	len;
	int	negative;

	i = 0;
	negative = 0;
	if (arg[0] == '-')
	{
		i++;
		negative = 1;
	}
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i] || (negative == 1 && i == 1))
		return (0);
	i = skip_zeros(arg);
	len = ft_strlen(&arg[i]);
	if (len > 19
		|| (len == 19 && negative == 0
			&& ft_strncmp("9223372036854775807", &arg[i], 20) < 0)
		|| (len == 19 && negative == 1
			&& ft_strncmp("9223372036854775808", &arg[i], 20) < 0))
		return (0);
	return (1);
}

void	builtins_exit_prog(int ac, char **av)
{
	long long int	nb;

	if (!good_arg_for_exit(av[1]))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_all();
		exit(2);
	}
	else if (good_arg_for_exit(av[1]) && ac == 2)
	{
		nb = ft_atoi_long_long(av[1]);
		free_all();
		exit(nb % 256);
	}
}

int	ft_exit(int ac, char **av)
{
	ft_putstr_fd("exit\n", 2);
	if (ac == 1)
	{
		free_all();
		exit(g_exit_status % 256);
	}
	builtins_exit_prog(ac, av);
	ft_putstr_fd("exit: too many arguments\n", 2);
	return (1);
}
