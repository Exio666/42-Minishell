/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:53:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/13 17:19:37 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd_absolu_path(char *path_move)
{
	if (chdir(path_move) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path_move, 2);
		return (1);
	}
	else
		return (0);
}

int ft_cd_relative_path(char *path_move)
{
	char *pwd[2048];

	getcwd(str, 2048);
	if (!str)
		return (1);
}

int	ft_cd_movedir(char *path_move)
{
	if (path_move[0] == '/')
		return (ft_cd_absolu_path(path_move));
	else
		return (ft_cd_relative_path(path_move));
}

int	ft_cd(int ac, char *argv, t_lst_env **envp)
{
	char *path_move;
	if (ac > 1)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	else if (ac == 1)
	{
		path_move = ft_get_env(envp, "HOME");
		if (path_move == NULL)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
		path_move = argv[1];
	return(ft_cd_movedir(path_move));
}