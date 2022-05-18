/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:58:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 20:33:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_print_fd(char *str1, char *str2, int fd)
{
	ft_putstr_fd(str1, fd);
	ft_putstr_fd(str2, fd);
}

int	ft_print_not_found(char *cmd, char **all_path, int i)
{
	char	*full_path_command;

	full_path_command = cmd;
	while (all_path && all_path[i])
	{
		if (access(full_path_command, F_OK) == 0)
		{
			if (access(full_path_command, X_OK | R_OK) != 0)
			{
				if (isatty(STDIN_FILENO))
					double_print_fd(cmd, ": Permission denied.\n", 2);
				return (126);
			}
		}
		full_path_command = ft_strjoin(all_path[i], cmd);
		i++;
	}
	if (isatty(STDIN_FILENO))
		double_print_fd(cmd, ": command not found\n", 2);
	return (127);
}
