/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:52 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 17:06:15 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_tab_to_list.h"

int	main(int argc, char **argv, char **envp)
{
	t_lst_env	*list_elem;

	(void)(argc);
	(void)(argv);
	list_elem = transform_env_array_in_list(envp);
	print_lst_env(list_elem);
	__ft_calloc(-1);
	return (0);
}

void	print_lst_env(t_lst_env	*list_elem)
{
	while (list_elem)
	{
		printf("%s = %s\n", list_elem->name, list_elem->content);
		list_elem = list_elem->next;
	}
}
