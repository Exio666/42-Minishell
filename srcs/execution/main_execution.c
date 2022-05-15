/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:24:19 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// echo $a""'''""''"""""''$a'"'$a'"

#include "minishell.h"

int	g_exit_status = 0;

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
	__ft_calloc_env(-1);
	__ft_calloc(-1);
	rl_clear_history();
	exit(g_exit_status);
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
		if (g_exit_status == 386)
			g_exit_status = 130;
		signal(SIGQUIT, &handler_sigquit_empty);
		signal(SIGINT, &handler_sigint_prompt);
		reset_terminal();
		command_line = readline(prompt);
		add_history(command_line);
		if (primary_checker(command_line) == TRUE && check_all_pipe_sequence(command_line) == TRUE)
		{
			root = get_btree_of_logical_op(command_line);
			add_all_pipe_sequence_in_tree(&root, command_line);
			create_all_heredoc(&root, command_line);
			free(command_line);
			execute_command_tree(root, &env_list);
			__ft_calloc(-1);
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
