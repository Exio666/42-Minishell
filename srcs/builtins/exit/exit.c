/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:44:31 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 13:21:02 by bsavinel         ###   ########.fr       */
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

int	ft_exit(int ac, char **av)
{
	if (ac == 1)
	{
		__ft_calloc(-1);
		exit(0);
	}
	if (!(good_arg_for_exit(av[1]) && ac > 2))
	{
		__ft_calloc(-1);
		if (ac == 1)
			exit(1);
		if (!good_arg_for_exit(av[1]))
		{
			__ft_calloc(-1);
			exit(2);
		}
		else
		{
			__ft_calloc(-1);
			exit(ft_atoi(av[1]));
		}
	}
	return (1);
}
