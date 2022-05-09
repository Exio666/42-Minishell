/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/09 17:54:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_terminal(void)
{
	int		fd_terminal;
	int		error;

	error = 0;
	fd_terminal = open("/dev/tty", O_RDWR);
	if (fd_terminal == -1)
		error = -1;
	if (error != -1)
		error = dup2(fd_terminal, STDIN_FILENO);
	if (error != -1)
		error = dup2(fd_terminal, STDOUT_FILENO);
	if (error != -1)
		error = dup2(fd_terminal, STDERR_FILENO);
	close(fd_terminal);
	if (error == -1)
	{
		ft_putendl_fd("Error: Fatal bad open of file\n", 2);
		rl_clear_history();
		__ft_calloc(-1);
		exit(1);
	}
}

void	exit_ctr_d(char *command_line)
{
	printf(RED_BOLD);
	printf("exit\n");
	printf(RESET);
	free(command_line);
	__ft_calloc(-1);
	exit(130);
}

int	main(int argc, char **argv, char **envp)
{
	char		*command_line;
	t_btree		*root;
	t_lst_env	*env_list;
	const char	prompt[] = GRN "Bsavinel_and_associates_shell$ " RESET;

	(void)(argc);
	(void)(argv);
	env_list = convert_env_array_in_list(envp);
	while (42)
	{
		signal(SIGQUIT, &handler_sigquit_empty);
		signal(SIGINT, &handler_sigint_prompt);
		reset_terminal();
		command_line = readline(prompt);
		add_history(command_line);
		if (primary_checker(command_line) == TRUE)
		{
			signal(SIGINT, &handler_sigint_endl);
			signal(SIGQUIT, &handler_sigquit_exit);
			root = get_btree_of_logical_op(command_line);
			add_all_pipe_sequence_in_tree(&root, command_line);
			free(command_line);
			execute_command_tree(root, &env_list);
		}
		else if (!command_line)
		{
			free(command_line);
			exit_ctr_d(command_line);
		}
	}
	__ft_calloc(-1);
	return (0);
}

/* Bloc de debugage */
			/*split = split_by_separator(command_line, "|<>");
		
			printf("------------------------------\n");
			print_split_tab(split);
			printf("------------------------------\n");
			lst_token = create_token_list(split);
			print_split_lst(lst_token);
	
			printf("------------------------------\n");
		
			execute_here_doc_tree(root);
			print2D(root);
		
			printf("------------------------------\n");*/