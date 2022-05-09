/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:44:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 13:41:09 by bsavinel         ###   ########.fr       */
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
	int	nb;

	if (ac == 1)
	{
		__ft_calloc(-1);
		rl_clear_history();
		exit(1);
	}
	else if (!good_arg_for_exit(av[1]))
	{
		__ft_calloc(-1);
		rl_clear_history();
		exit(2);
	}
	else
	{
		nb = ft_atoi(av[1]);
		__ft_calloc(-1);
		rl_clear_history();
		exit(nb);
	}
}

int	ft_exit(int ac, char **av)
{
	if (ac == 1)
	{
		__ft_calloc(-1);
		rl_clear_history();
		exit(0);
	}
	if (!(good_arg_for_exit(av[1]) && ac > 2))
	{
		builtins_exit_prog(ac, av);
	}
	return (1);
}
