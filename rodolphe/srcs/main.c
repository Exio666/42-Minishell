/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:37:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/30 10:38:33 by rpottier         ###   ########.fr       */
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

char *get_path_env_variable(char **envp)
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
		path_len = strlen(all_path[i]);
		current_path = malloc(sizeof(*current_path) * (path_len + 2));
		if (!current_path)
			return (NULL);
		ft_strlcpy(current_path, all_path[i], path_len + 1);
		current_path[path_len] = '/';
		current_path[path_len + 1] = '\0';
		free(all_path[i]);
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

void execute_command(char **exe_argv, char **all_path)
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
			exe_read = execve(full_path_command, exe_argv, all_path);
			free(full_path_command);
		}
		i++;
	}
}

int	open_input_file(char *input_file_name)
{
	char	*input_file_fd;

	input_file_fd = open(input_file_name, O_RDONLY);
	if (input_file_fd == -1)
		exit(EXIT_FAILURE);
	return (input_file_fd);
}

int	open_output_file(char *output_file_name)
{
	char	*output_file_fd;

	output_file_fd = open(output_file_name, O_RDONLY);
	if (output_file_fd == -1)
		exit(EXIT_FAILURE);
	return (output_file_fd);
}

int main(int ac, char **av, char **envp)
{
	char **exe_argv_1;
	char **exe_argv_2;
	char	**all_path;
	int		fd_pipe[2];
	int		pid;
	int		input_file_fd;
	int		output_file_fd;

	all_path = split_path_env_variable_and_add_slash(get_path_env_variable(envp));

	if (ac < 5)
		return (0);
	
	pid = fork();
	
	wait(NULL);
	if (pid == 0)
	{	
		input_file_fd = open_input_file(av[1]);
		output_file_fd = open_output_file(av[4]);
		exe_argv_1 = parse_arg(av[2]);
		exe_argv_2 = parse_arg(av[3]);
		pipe(fd_pipe);
		pid = fork();
		if (pid == 0)
		{
			dup2(input_file_fd, STDIN_FILENO);
			dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
			close(input_file_fd);
			close(fd_pipe[READ_END]);
			execute_command(exe_argv_1, all_path);
		}
		else
		{	
			dup2(output_file_fd, STDOUT_FILENO);
			dup2(fd_pipe[READ_END], STDIN_FILENO);
		//	close(input_file_fd);
		//	close(output_file_fd);
			close(fd_pipe[WRITE_END]);
			execute_command(exe_argv_2, all_path);
			wait(NULL);
		}
	}
	return (0);	
}