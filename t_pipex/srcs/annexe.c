/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:22:34 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 13:51:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/pipex.h"

char **parse_arg(char *arg)
{
	char **arg_with_option;
	
	arg_with_option = ft_split(arg, ' ');
	if (!arg_with_option)
		return (NULL);
	return (arg_with_option);
}

char *get_path_env_variable_from_array(char **envp)
{
	int i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char **split_path_env_variable_and_add_slash(char *path_env_variable)
{
	char *current_path;
	char **all_path;
	int i;
	int path_len;
	
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
char *get_name_command(char **exe_argv)
{
	char *name_command;

	if (exe_argv == NULL)
		return (NULL);
	name_command = ft_strdup(exe_argv[0]);
	return (name_command);
}

void execute(char **exe_argv, char **all_path, char **envp)
{
	int		exe_read = -1;
	char	*full_path_command;
	int		i;	

	i = 0;
	while (all_path[i] && exe_read == -1)
	{
		if (access(all_path[i], X_OK) == 0)
		{
			full_path_command = ft_strjoin(all_path[i], exe_argv[0]);
			exe_read = execve(full_path_command, exe_argv, envp);
		}
		i++;
	}
}

int	open_input_file(char *input_file_name)
{
	int input_file_fd;

	input_file_fd = open(input_file_name, O_RDONLY);
	if (input_file_fd == -1)
		exit(EXIT_FAILURE);
	return (input_file_fd);
}

int	open_output_file(char *output_file_name)
{
	int	output_file_fd;

	output_file_fd = open(output_file_name, O_WRONLY | O_CREAT, 00777);
	if (output_file_fd == -1)
		exit(EXIT_FAILURE);
	return (output_file_fd);
} 