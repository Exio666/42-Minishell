/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_path_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:16:25 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 10:21:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*path_variable;
	char		**split_path_env;
	t_lst_env	*list_elem;
	(void)(argc);
	(void)(argv);

	list_elem = convert_env_array_in_list(envp);
	print_lst_env(list_elem);
	path_variable = get_path_env_variable(list_elem);
	
	printf("---------\n%s\n", path_variable);

	split_path_env = split_path_env_variable(path_variable);

	printf("---------\n");

	print_char_two_dim_array(split_path_env);
	//free_char_two_dim_array(split_path_env);
	//free_t_lst_env(list_elem);
	__ft_calloc(-1);
	return (0);
}
