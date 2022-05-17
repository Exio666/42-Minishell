/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:15:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 10:11:46 by bsavinel         ###   ########.fr       */
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

void	feed_heredoc(int fd, char *end)
{
	char	*str;
	int		line;

	line = 0;
	while (1)
	{
		str = readline("> ");
		if (str == NULL)
		{
			ctrl_d_heredoc(end, line);
			return ;
		}
		if (ft_strncmp(str, end, ft_strlen(end) + 2) == 0 || !str)
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

void	exec_heredoc(int fd, char *end)
{
	signal(SIGINT, &handler_sigint_heredoc);
	feed_heredoc(fd, end);
	close(fd);
	free_all();
	exit(0);
}

char	*fork_heredoc(int fd, char *end, char *str)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
		exec_heredoc(fd, end);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == 130)
		g_exit_status = 386;
	close(fd);
	return (str);
}

char	*heredoc_create(char *end)
{
	char	*str;
	int		fd;

	fd = -1;
	str = ft_strdup("/tmp/.heredoc_000");
	while (1 && g_exit_status != 386)
	{
		fd = open(str, O_CREAT | O_RDWR | O_EXCL, 0777);
		if (fd >= 0)
			return (fork_heredoc(fd, end, str));
		if (!change_name_heredoc(str))
		{
			ft_putstr_fd("Heredoc creation failed\n", 2);
			str = ft_strdup("/dev/null");
			return (str);
		}
	}
	return (NULL);
}
