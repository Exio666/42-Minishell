/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:15:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/02 14:33:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_name_heredoc(char *str);
{
	if (str[12] != 122)
	{
		str[12] = str[12] + 1;
	}
	else if (str[13] != 122)
	{
		str[12] = '0';
		str[13] = str[13] + 1;
	}
	else if (str[14] != 122)
	{
		str[12] = '0';
		str[13] = '0';
		str[14] = str[14] + 1;
	}
	else
		return (0);
	return (1);
}

void	feed_herdoc(int fd, char *end)
{
	char	str;

	while (1)
	{
		str = readline("> ");
		if (ft_strncmp(str, end, ft_strlen(end)) == 0 || ft_strlen(str) == 0)
			return ;
		ft_putstr_fd(str, fd);
	}
}

char	*heredoc_create(char *end)
{
	char	*str;
	int		counter;
	int		fd;

	fd = -1;
	str = __ft_calloc(sizeof(char) * 17);
	str = "/tmp/herdoc_000";
	while (1)
	{
		open(str, O_CREAT | O_RDWR | O_EXCL, 0777);
		if (fd != -1)
		{
			feed_herdoc(fd, end);
			close(fd);
			return (str);
		}
		if (!change_name_heredoc(str))
			return (NULL);
	}
	return (NULL);
}
