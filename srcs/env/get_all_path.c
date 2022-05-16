/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:48:21 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/16 09:13:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_arg(char *arg)
{
	char	**arg_with_option;

	arg_with_option = ft_split(arg, ' ');
	if (!arg_with_option)
		return (NULL);
	return (arg_with_option);
}

char	*get_path_env_variable_from_array(char **envp)
{
	int	i;

	i = 0;
	if (envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	**split_path_env_variable_and_add_slash(char *path_env_variable)
{
	char	*current_path;
	char	**all_path;
	int		i;
	int		path_len;

	if (!path_env_variable)
		return (NULL);
	all_path = ft_split(ft_strchr(path_env_variable, '=') + 1, ':');
	i = 0;
	while (all_path[i] != NULL && all_path[i][0] != 0)
	{
		path_len = ft_strlen(all_path[i]);
		current_path = __ft_calloc(sizeof(*current_path) * (path_len + 2));
		if (!current_path)
			return (NULL);
		ft_strlcpy(current_path, all_path[i], path_len + 1);
		current_path[path_len] = '/';
		current_path[path_len + 1] = '\0';
		all_path[i] = current_path;
		i++;
	}
	return (all_path);
}

char	*get_name_command(char **exe_argv)
{
	char	*name_command;

	if (exe_argv == NULL)
		return (NULL);
	name_command = ft_strdup(exe_argv[0]);
	return (name_command);
}

int	execute(char **exe_argv, t_lst_env **env_list)
{
	int		exe_read;
	char	*full_path_command;
	int		i;
	char	**all_path;
	char	**envp;

	exe_read = -1;
	envp = env_list_to_tab(env_list);
	all_path = split_path_env_variable_and_add_slash(
			get_path_env_variable_from_array(envp));
	i = 0;
	exe_read = execve(exe_argv[0], exe_argv, envp);
	while (*env_list != NULL && all_path[i] && exe_read == -1)
	{
		if (access(all_path[i], X_OK) == 0)
		{
			full_path_command = ft_strjoin(all_path[i], exe_argv[0]);
			exe_read = execve(full_path_command, exe_argv, envp);
		}
		i++;
	}
	ft_print_not_found(exe_argv[0]);
	return (ERROR_EXECVE);
}
