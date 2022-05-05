/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/05 14:37:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char **argv, char **envp)
{
	(void) (argc);
	(void) (argv);

//	launch_test_a_equal_bonjour_with_space(envp);
	launch_test_a_equal_cho_a(envp);
	return (0);
}

/*
int	main(int argc, char **argv, char **envp)
{

	t_list *lst_token;
	char **split;
	t_list *lst;
	char	*command_line;
	t_btree *root;
	t_lst_env *env_list;

	(void)(argc);
	(void)(argv);
	const char	prompt[] = GRN "AirPottier_shell$ " RESET;

	while (42)
	{
		command_line = readline(prompt);
		if (strcmp(command_line, "EXIT") == 0)
		{
			free(command_line);
			rl_clear_history();
			return (0);
		}
		add_history(command_line);

	if(primary_checker(command_line) == TRUE)
	{
	//	printf("The checker say 'commande is good'\n");
		root = get_btree_of_logical_op(command_line);
		add_all_pipe_sequence_in_tree(&root, command_line);
		
		
//		split = split_by_separator(command_line, "|<>");
//		
//		printf("------------------------------\n");
//		print_split_tab(split);
//		printf("------------------------------\n");
//		lst_token = create_token_list(split);
//		
//		print_split_lst(lst_token);
//
		
//		printf("------------------------------\n");
		env_list = convert_env_array_in_list(envp);
		//execute_here_doc_tree(root);
		execute_command_tree(root, env_list);
		
//		print2D(root);
//		printf("------------------------------\n");
	}
	else
	{	
		
	//	printf("The checker say 'commande is bad'\n");
	
	}
	free(command_line);
	__ft_calloc(-1);
	}
	
	return (0);
}
*/
/*
export a="cho a"

e$a   -> a
e'$a' -> Command 'e$a' not found
e"$a" -> echo a: command not found

export a="cho ' 'a"

e$a   -> ' ' a
e'$a' -> Command 'e$a' not found
e"$a" -> echo a: command not found


export a="cho  $b a"
export a="cho '$b' a"

export a=BENOIT
export b=SAVINEL
echo -n BONJOUR $a && echo -n ' ' && echo $b
*/