/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:43:02 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/30 11:25:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

# define WRITE_END 1
# define READ_END 0

char    **parse_arg(char *arg);
char    *get_path_env_variable(char **envp);
char    **split_path_env_variable_and_add_slash(char *path_env_variable);
char    *get_name_command(char **exe_argv);
void    execute_command(char **exe_argv, char **all_path, char **envp);
int     open_input_file(char *input_file_name);
int     open_output_file(char *output_file_name);

#endif