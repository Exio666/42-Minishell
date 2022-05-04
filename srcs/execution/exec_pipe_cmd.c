/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:27:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 13:27:53 by bsavinel         ###   ########.fr       */
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
	char **argv;
	int retour;

	argv = create_argv_cmd(token);
	//set_up_redirect_in(token);
	//set_up_redirect_out(token);
	retour = exec_builtins(len_av(argv), argv, env_list);
	if (retour == 127)
		execute(argv, env_list);
	exit(retour);
}

int	exec_pipe_cmd(t_lst_token *token, t_lst_env **env_list, int nb_cmd)
{
	int		pipe_stock[2];
	int		new_pipe[2];
	int		i;
	int		pid;

	i = 0;
	while (i < nb_cmd)
	{
		pipe(new_pipe);
		pid = fork();
		if (pid == 0)
		{
			if (i != nb_cmd - 1)
				dup2(new_pipe[0], STDOUT_FILENO);
			close(new_pipe[0]);
			close(new_pipe[1]);
			if (i != 0)
				dup2(pipe_stock[1], STDIN_FILENO);
			close(pipe_stock[0]);
			close(pipe_stock[1]);
			exec_cmd(token, env_list);
		}
		while (token && token->type != TOK_PIPE)
			token = token->next;
		if (token && token->type == TOK_PIPE)
			token = token->next;
		close(pipe_stock[0]);
		close(pipe_stock[1]);
		pipe_stock[0] = new_pipe[0];
		pipe_stock[1] = new_pipe[1];
		i++;
	}
	close(pipe_stock[0]);
	close(pipe_stock[1]);
	while (waitpid(-1, NULL, 0) > 0) //Permet au programe principale d'attendre tout les enfants
			;
	return (0);
}