/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 10:33:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	char		*command_line;
	t_lst_env	**env_list;
	const char	prompt[] = GRN "AirPottier_shell$ " RESET;

	(void)(argc);
	(void)(argv);
	env_list = convert_env_array_in_list(envp);
	while (42)
	{
		if (g_exit_status == 386)
			g_exit_status = 130;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &handler_sigint_prompt);
		command_line = get_command_line(prompt);
		add_history(command_line);
		if (command_line && check_command_is_ok(command_line))
			process_command(command_line, env_list);
		else if (!command_line)
			exit_ctr_d();
		__ft_calloc(-1);
	}
	return (0);
}

void	exit_ctr_d(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf(RED_BOLD);
		printf("exit\n");
		printf(RESET);
	}
	__ft_calloc_env(-1);
	__ft_calloc(-1);
	rl_clear_history();
	exit(g_exit_status);
}

void	process_command(char *command_line, t_lst_env **env_list)
{
	t_btree		*root;

	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	create_all_heredoc(&root, command_line);
	execute_command_tree(root, env_list);
	__ft_calloc(-1);
}

char	*get_command_line(const char *prompt)
{
	char	*command_line_to_free;
	char	*command_line;

	if (isatty(STDIN_FILENO))
	{
		rl_replace_line("", 0);
		command_line_to_free = readline(prompt);
	}
	else
	{
		command_line_to_free = get_next_line(0);
		if (command_line_to_free)
			command_line_to_free[ft_strlen(command_line_to_free) - 1] = '\0';
	}
	command_line = ft_strdup(command_line_to_free);
	free(command_line_to_free);
	return (command_line);
}
