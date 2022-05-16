/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:53:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 17:41:17 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_absolu_path(char *path_move, t_lst_env **envp)
{
	char	*pwd;

	if (chdir(path_move) == -1)
	{
		ft_putstr_fd(CD_ERROR_NO_DIR, 2);
		ft_putendl_fd(path_move, 2);
		return (1);
	}
	else
	{
		pwd = get_variable_content(ft_get_env(envp, "PWD"));
		put_variable(ft_strjoin("OLDPWD=", pwd), envp);
		pwd = __ft_calloc(sizeof(char) * 2048);
		getcwd(pwd, 2048);
		if (!pwd)
			return (1);
		put_variable(ft_strjoin("PWD=", pwd), envp);
		return (0);
	}
}

int	no_dir(char *path_move)
{
	ft_putstr_fd(CD_ERROR_NO_DIR, 2);
	ft_putendl_fd(path_move, 2);
	return (1);
}

int	ft_cd_relative_path(char *path_move, t_lst_env **envp)
{
	char	*pwd;
	char	*tmp;

	pwd = __ft_calloc(sizeof(char) * 2048);
	getcwd(pwd, 2048);
	if (!pwd)
		return (1);
	tmp = ft_strjoin(pwd, "/");
	tmp = ft_strjoin(tmp, path_move);
	if (chdir(tmp) == -1)
		return (no_dir(path_move));
	else
	{
		pwd = get_variable_content(ft_get_env(envp, "PWD"));
		put_variable(ft_strjoin("OLDPWD=", pwd), envp);
		pwd = __ft_calloc(sizeof(char) * 2048);
		getcwd(pwd, 2048);
		if (!pwd)
			return (1);
		put_variable(ft_strjoin("PWD=", pwd), envp);
		return (0);
	}
}

int	ft_cd_movedir(char *path_move, t_lst_env **envp)
{
	if (path_move[0] == '/')
		return (ft_cd_absolu_path(path_move, envp));
	else
		return (ft_cd_relative_path(path_move, envp));
}

int	ft_cd(int ac, char **argv, t_lst_env **envp)
{
	char	*path_move;

	if (ac > 2)
	{
		ft_putstr_fd(CD_TOO_MANY_ARGS, 2);
		return (1);
	}
	else if (ac == 1)
	{
		path_move = get_variable_content(ft_get_env(envp, "HOME"));
		if (path_move == NULL)
		{
			ft_putstr_fd(CD_ERROR_HOME_MOT_SET, 2);
			return (1);
		}
	}
	else
		path_move = argv[1];
	return (ft_cd_movedir(path_move, envp));
}
