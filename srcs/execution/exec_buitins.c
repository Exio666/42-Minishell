/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_buitins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:42:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 13:31:16 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_builtins(int ac, char **av, t_lst_env **envp)
{
	fprintf(stderr, "commande dans exec builtins: %s\n", av[0]);
	if (ft_strncmp(av[0], "cd", 3) == 0)
	{
		fprintf(stderr,  "Builtin cd\n");
		return (ft_cd(ac, av, envp));
	}
	else if (ft_strncmp(av[0], "echo", 5) == 0)
	{
		fprintf(stderr,  "Builtin echo\n");
		return (echo(ac, av));
	}
	else if (ft_strncmp(av[0], "env", 4) == 0)
	{
		fprintf(stderr,  "Builtin env\n");
		return (ft_aff_env(envp));
	}
	else if (ft_strncmp(av[0], "exit", 5) == 0)
	{
		fprintf(stderr,  "Builtin exit\n");
		return (ft_exit(ac, av));
	}
	else if (ft_strncmp(av[0], "export", 6) == 0)
	{
		fprintf(stderr,  "Builtin export\n");
		return (ft_export(ac, av, envp));
	}
	else if (ft_strncmp(av[0], "pwd", 4) == 0)
	{
		fprintf(stderr,  "Builtin pwd\n");
		return (ft_pwd());
	}
	else if (ft_strncmp(av[0], "unset", 6) == 0)
	{
		fprintf(stderr,  "Builtin unset\n");
		return (ft_unset(ac, av, envp));
	}
	return (127);
}