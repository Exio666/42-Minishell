/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:36:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/26 16:29:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_2d_array_length(char **array)
{
	int length;

	if (!array)
		return (-1);
	length = 0;
	while (array[length])
	{
		
		length++;
	}
}

int check_export_arg(char **argv)
{
	
}

//argv doit se terminer par NULL

void ft_export(char	**argv, t_lst_env *env_list)
{
	int argv_length;

	argv_length = get_2d_array_length(argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_lst_env	*env_list;
	(void)(argc);
	(void)(argv);
	env_list = convert_env_array_in_list(envp);
	print_lst_env(env_list);
	__ft_calloc(-1);
	return (0);
}
