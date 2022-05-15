/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:52 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 10:19:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_lst_env	*list_elem;

	(void)(argc);
	(void)(argv);
	list_elem = convert_env_array_in_list(envp);
	print_lst_env(list_elem);
	__ft_calloc(-1);
	return (0);
}
