/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:44:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 15:53:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	good_arg_for_exit(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i])
		return (0);
	return (1);
}

void	builtins_exit_prog(int ac, char **av)
{
	long long int	nb;

	if (!good_arg_for_exit(av[1]))
	{
		__ft_calloc(-1);
		rl_clear_history();
		ft_putstr_fd("exit: qerq: numeric argument required\n", 2);
		exit(2);
	}
	else if (good_arg_for_exit(av[1]) && ac == 2)
	{
		nb = ft_atoi_long_long(av[1]);
		__ft_calloc(-1);
		rl_clear_history();
		exit(nb % 256);
	}
}

int	ft_exit(int ac, char **av)
{
	ft_putstr_fd("exit\n", 2);
	if (ac == 1)
	{
		__ft_calloc(-1);
		rl_clear_history();
		exit(g_exit_status % 256);
	}
	builtins_exit_prog(ac, av);
	ft_putstr_fd("exit: too many arguments\n", 2);
	return (1);
}
