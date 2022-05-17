/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:27:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 09:52:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	int		retour;

	argv = create_argv_cmd(token);
	set_up_redirect(token, 1);
	retour = exec_builtins(ft_size_2d_array(argv), argv, env_list);
	if (retour == 127)
		execute(argv, env_list);
	rl_clear_history();
	__ft_calloc(-1);
	__ft_calloc_env(-1);
	exit(retour);
}

void	dup_std_fileno(int pipe_stock[2], int new_pipe[2], int nb_cmd, int i)
{
	if (i != nb_cmd - 1)
		dup2(new_pipe[1], STDOUT_FILENO);
	if (i != 0)
		dup2(pipe_stock[0], STDIN_FILENO);
	multi_close(pipe_stock[0], pipe_stock[1], new_pipe[0], new_pipe[1]);
}

void	end_pipe_execution(int pid, int pipe_stock[2])
{
	int		status;

	multi_close(pipe_stock[0], pipe_stock[1], -1, -1);
	waitpid(pid, &status, 0);
	exit_code_management(status);
	while (waitpid(-1, NULL, 0) > 0)
		;
}

int	exec_pipe_cmd(t_lst_token *token, t_lst_env **env_list, int nb_cmd)
{
	int		pipe_stock[2];
	int		new_pipe[2];
	int		i;
	int		pid;

	i = init_pipe_fd(pipe_stock, new_pipe);
	while (i < nb_cmd)
	{
		if (pipe(new_pipe) == -1)
			failed_pipe(pipe_stock, new_pipe);
		pid = fork();
		if (pid == 0)
		{
			dup_std_fileno(pipe_stock, new_pipe, nb_cmd, i);
			exec_cmd(token, env_list);
		}
		token = move_to_next_pipe(token);
		if (i != 0)
			multi_close(pipe_stock[0], pipe_stock[1], -1, -1);
		pipe_stock[0] = new_pipe[0];
		pipe_stock[1] = new_pipe[1];
		i++;
	}
	end_pipe_execution(pid, pipe_stock);
	return (0);
}
