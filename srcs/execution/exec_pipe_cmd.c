/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:27:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 16:35:00 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_av(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	exec_cmd(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	int		retour;

	argv = create_argv_cmd(token);
	set_up_redirect(token, 1);
	retour = exec_builtins(len_av(argv), argv, env_list);
	if (retour == 127)
		execute(argv, env_list);
	rl_clear_history();
	__ft_calloc(-1);
	__ft_calloc_env(-1);
	exit(retour);
}

void	multi_close(int fd_1, int fd_2, int fd_3, int fd_4)
{
	if (fd_1 != -1)
		close(fd_1);
	if (fd_2 != -1)
		close(fd_2);
	if (fd_3 != -1)
		close(fd_3);
	if (fd_4 != -1)
		close(fd_4);
}

void init_pipe_fd(int pipe[2])
{
	pipe[0] = -1;
	pipe[1] = -1;
}

int	exec_pipe_cmd(t_lst_token *token, t_lst_env **env_list, int nb_cmd)
{
	int		pipe_stock[2];
	int		new_pipe[2];
	int		i;
	int		pid;
	int		status;

	i = 0;
	init_pipe_fd(pipe_stock);
	init_pipe_fd(new_pipe);
	while (i < nb_cmd)
	{
		if (pipe(new_pipe) == -1)
		{
			while (waitpid(-1, NULL, 0) > 0)
				;
			multi_close(pipe_stock[0], pipe_stock[1], new_pipe[0], new_pipe[1]);
			free_all();
		}
		pid = fork();
		if (pid == 0)
		{
			if (i != nb_cmd - 1)
				dup2(new_pipe[1], STDOUT_FILENO);
			if (i != 0)
				dup2(pipe_stock[0], STDIN_FILENO);
			multi_close(pipe_stock[0], pipe_stock[1], new_pipe[0], new_pipe[1]);
			exec_cmd(token, env_list);
		}
		while (token && token->type != TOK_PIPE)
			token = token->next;
		if (token && token->type == TOK_PIPE)
			token = token->next;
		if (i != 0)
			multi_close(pipe_stock[0], pipe_stock[1], -1, -1);
		pipe_stock[0] = new_pipe[0];
		pipe_stock[1] = new_pipe[1];
		i++;
	}
	multi_close(pipe_stock[0], pipe_stock[1], -1, -1);
	waitpid(pid, &status, 0);
	exit_code_management(status);
	while (waitpid(-1, NULL, 0) > 0)
		;
	return (0);
}
