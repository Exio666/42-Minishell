/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:23:39 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/25 08:52:48 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define RESET "\x1B[0m"

//int	main(int argc, char **argv)
int	main(void)
{
	char **split;
	t_list *lst;
	char	*command_line;
	t_btree *root;
	const char	prompt[] = GRN " Airpottier_shell$ " RESET;

	while (42)
	{
		command_line = readline(prompt);
		add_history(command_line);
		printf("%s\n", command_line);

	if(primary_checker(command_line) == TRUE)
	{
		printf("The checker say 'commande is good'\n");
		root = get_btree_of_logical_op(command_line);
		add_all_pipe_sequence_in_tree(&root, command_line);
		/*
		split = split_by_separator(command_line, "|<>");
		print_split_tab(split);

		lst = create_token_list(split);
		print_split_lst(lst);
*/
		print2D(root);
		free(command_line);

	
	}
	else
	{	
		
		printf("The checker say 'commande is bad'\n");
	
	}

	}
	return (0);
}



































/*
		printf("%s\n", command_line);
		split = split_by_separator(command_line, "|<>");
		print_split_tab(split);

		lst = create_token_list(split);
		print_split_lst(lst);
*/