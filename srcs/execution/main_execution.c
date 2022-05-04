/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 13:59:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*command_line;
	t_btree		*root;
	t_lst_env	*env_list;
	int			fd_terminal;

	(void)(argc);
	(void)(argv);
	const char	prompt[] = GRN "Bsavinel_and_associates_shell$ " RESET;
	env_list = convert_env_array_in_list(envp);
	while (42)
	{
		fd_terminal = open("/dev/tty", O_RDWR);
		dup2(fd_terminal, STDIN_FILENO);
		dup2(fd_terminal, STDOUT_FILENO);
		close(fd_terminal);
		command_line = readline(prompt);
		add_history(command_line);
		if(ft_strlen(command_line) > 1 && primary_checker(command_line) == TRUE)
		{
			//printf("The checker say 'commande is good'\n");
			root = get_btree_of_logical_op(command_line);
			add_all_pipe_sequence_in_tree(&root, command_line);
		
			/*
			split = split_by_separator(command_line, "|<>");
		
			printf("------------------------------\n");
			print_split_tab(split);
			printf("------------------------------\n");
			lst_token = create_token_list(split);
			print_split_lst(lst_token);
			*/
	
			//printf("------------------------------\n");
		
			//execute_here_doc_tree(root);
			//print2D(root);
		
			//printf("------------------------------\n");
			execute_command_tree(root, &env_list);
		}
		/*else
			printf("The checker say 'commande is bad'\n");*/
		free(command_line);
	}
	__ft_calloc(-1);
	return (0);
}