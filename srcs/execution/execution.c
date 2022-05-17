/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 09:54:53 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_tree(t_btree *root, t_lst_env **env_list)
{
	if (!root)
		return ;
	execute_command_tree(root->left, env_list);
	save_fd(1);
	if (root->token && g_exit_status != 386)
		execute_command(root->token, env_list);
	save_fd(2);
	save_fd(3);
	if (root->logic_op
		&& ((g_exit_status == 0 && root->logic_op->type == 1)
			|| (g_exit_status != 0 && root->logic_op->type == 2)))
		execute_command_tree(root->right, env_list);
}

void	exit_code_management(int status)
{
	if (WIFEXITED(status))
	{
		g_exit_status = WEXITSTATUS(status);
		return ;
	}
	if (WIFSIGNALED(status))
	{
		g_exit_status = 128 + WTERMSIG(status);
		ft_putstr_fd("Core dumped by the signal number ", 2);
		ft_putnbr_fd(WTERMSIG(status), 2);
		ft_putstr_fd("\n", 2);
	}
	else
		g_exit_status = 0;
	return ;
}

int	exec_one_cmd(char **argv, t_lst_env **env_list)
{
	int	retour;
	int	pid;

	retour = exec_builtins(ft_size_2d_array(argv), argv, env_list);
	if (retour == 127)
	{
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, &handler_sigquit_empty);
			execute(argv, env_list);
			rl_clear_history();
			__ft_calloc(-1);
			exit(127);
		}
		while (waitpid(-1, &retour, 0) > 0)
			;
		exit_code_management(retour);
	}
	else
		g_exit_status = retour;
	return (retour);
}

void	print_token_list(t_lst_token *token)
{
	while (token)
	{
		printf("%d | [%s]  ->  ", token->type, token->str);
		token = token->next;
	}
	printf("NULL\n");
}

int	execute_command(t_lst_token *token, t_lst_env **env_list)
{
	char	**argv;
	int		count;

	count = count_pipe(token);
	expand_command(token, *env_list);
	expand_wildcard_command(token);
	signal(SIGQUIT, &handler_sigquit_exit);
	signal(SIGINT, &handler_sigint_empty);
	if (count == 1)
	{
		if (set_up_redirect(token, 0) == 1)
			return (1);
		argv = create_argv_cmd(token);
		return (exec_one_cmd(argv, env_list));
	}
	else
		return (exec_pipe_cmd(token, env_list, count));
	return (0);
}
