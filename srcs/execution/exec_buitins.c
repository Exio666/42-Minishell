/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_buitins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:42:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 11:43:37 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_builtins(int ac, char **av, t_lst_env **envp)
{
	fprintf(stderr, "commande: %s\n", av[0]);
	if (ft_strncmp(av[0], "cd", 3) == 0)
	{
		ft_putstr_fd("Fonction cd :\n", 2);
		return (ft_cd(ac, av, envp));
	}
	else if (ft_strncmp(av[0], "echo", 5) == 0)
	{
		ft_putstr_fd("Fonction echo :\n", 2);
		return (echo(ac, av));
	}
	else if (ft_strncmp(av[0], "env", 4) == 0)
	{
		ft_putstr_fd("Fonction env :\n", 2);
		return (ft_aff_env(envp));
	}
	else if (ft_strncmp(av[0], "exit", 5) == 0)
	{
		ft_putstr_fd("Fonction exit :\n", 2);
		return (ft_exit(ac, av));
	}
	else if (ft_strncmp(av[0], "export", 6) == 0)
	{
		ft_putstr_fd("Fonction export :\n", 2);
		return (ft_export(ac, av, envp));
	}
	else if (ft_strncmp(av[0], "pwd", 4) == 0)
	{
		ft_putstr_fd("Fonction pwd :\n", 2);
		return (ft_pwd());
	}
	else if (ft_strncmp(av[0], "unset", 6) == 0)
	{
		ft_putstr_fd("Fonction unset :\n", 2);
		return (ft_unset(ac, av, envp));
	}
	return (127);
}