/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_path_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:16:25 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/12 22:01:16 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*path_variable;
	char		**split_path_env;
	t_lst_env	*list_elem;
	t_lst_env	*list_tmp;
	(void)(argc);
	(void)(argv);

	list_elem = transform_env_array_in_list(envp);
	print_lst_env(list_elem);
	path_variable = get_path_env_variable(list_elem);
	
	printf("---------\n%s\n", path_variable);

	split_path_env = split_path_env_variable(path_variable);

	printf("---------\n");

	print_char_two_dim_array(split_path_env);
	free_char_two_dim_array(char **array)
	free_t_lst_env(list_elem);
	__ft_calloc(-1);
	return (0);
}

void	free_char_two_dim_array(char **array)
{
	for(int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}
void	free_t_lst_env(t_lst_env	*list_elem)
{
		while (list_elem)
	{
		list_tmp = list_elem;
		list_elem = list_elem->next;
		free(list_tmp->content);
		free(list_tmp->name);
		free(list_tmp);
	}
}

void print_char_two_dim_array(char **array)
{
	for (int i = 0; array[i]; i++)
		printf("%s\n", array[i]);
}