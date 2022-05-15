/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 02:31:31 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 20:30:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
int main(int argc, char **argv, char **envp)
{
	t_lst_env	*env_list;
	char *command_line;
	const char	prompt[] = GRN " Airpottier_shell$ " RESET;

	env_list = convert_env_array_in_list(envp);

	while (42)
	{
		command_line = readline(prompt);
		add_history(command_line);
//		printf("%s\n", command_line);

		env_list = convert_env_array_in_list(envp);
		command_line = expand_command(command_line, env_list);
		if (command_line)
			printf("%s\n", command_line);
	}
	return (0);
}

*/