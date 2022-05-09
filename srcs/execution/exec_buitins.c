/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_buitins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:42:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 18:58:24 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtins(int ac, char **av, t_lst_env **envp)
{
	if (!av[0])
		return (127);
	if (ft_strncmp(av[0], "cd", 3) == 0)
		return (ft_cd(ac, av, envp));
	else if (ft_strncmp(av[0], "echo", 5) == 0)
		return (echo(ac, av));
	else if (ft_strncmp(av[0], "env", 4) == 0)
		return (ft_aff_env(envp));
	else if (ft_strncmp(av[0], "exit", 5) == 0)
		return (ft_exit(ac, av));
	else if (ft_strncmp(av[0], "export", 6) == 0)
		return (ft_export(ac, av, envp));
	else if (ft_strncmp(av[0], "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(av[0], "unset", 6) == 0)
		return (ft_unset(ac, av, envp));
	return (127);
}
