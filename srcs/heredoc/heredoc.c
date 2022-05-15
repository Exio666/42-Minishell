/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:15:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 18:07:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_name_heredoc(char *str)
{
	if (str[14] < 122)
	{
		str[14] = str[14] + 1;
	}
	else if (str[15] < 122)
	{
		str[14] = '0';
		str[15] = str[15] + 1;
	}
	else if (str[16] < 122)
	{
		str[14] = '0';
		str[15] = '0';
		str[16] = str[16] + 1;
	}
	else
		return (0);
	return (1);
}

void	ctrl_d_herdoc(char *end, int line)
{
	ft_putstr_fd("Warning: here-document at line ", 2);
	ft_putstr_fd(ft_itoa(line), 2);
	ft_putstr_fd(" delimited by end-of-file (wanted \'", 2);
	ft_putstr_fd(end, 2);
	ft_putstr_fd("\')\n", 2);
}

void	feed_herdoc(int fd, char *end)
{
	char	*str;
	int		line;

	line = 0;
	while (1)
	{
		str = readline("> ");
		if (str == NULL)
		{
			ctrl_d_herdoc(end, line);
			return ;
		}
		if (ft_strncmp(str, end, ft_strlen(end)) == 0 || ft_strlen(str) == 0)
		{
			free(str);
			return ;
		}
		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n", fd);
		free(str);
		line++;
	}
}

char	*heredoc_create(char *end)
{
	char	*str;
	int		fd;
	int		pid;
	int		status;

	fd = -1;
	str = ft_strdup("/tmp/.heredoc_000");
	while (1 && g_exit_status != 386)
	{
		fd = open(str, O_CREAT | O_RDWR | O_EXCL, 0777);
		if (fd >= 0)
		{
			pid = fork();
			if (pid == 0)
			{
				signal(SIGINT, &handler_sigint_heredoc);
				feed_herdoc(fd, end);
				close(fd);
				__ft_calloc(-1);
				exit(0);
			}
			waitpid(pid, &status, 0);
			if (WEXITSTATUS(status) == 130)
				g_exit_status = 386;
			close(fd);
			return (str);
		}
		if (!change_name_heredoc(str))
		{
			ft_putstr_fd("Heredoc creation failed\n", 2);
			str = "/dev/null";
			return (str);
		}
	}
	return (NULL);
}
