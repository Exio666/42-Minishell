/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_array_in_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:59:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 17:03:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	**convert_env_array_in_list(char **envp_array)
{
	t_lst_env	*head_list;
	t_lst_env	**retour;
	t_lst_env	*list_elem;
	int			i;

	head_list = NULL;
	i = 0;
	while (envp_array[i])
	{
		list_elem = create_list_env_elem(envp_array[i]);
		ft_dlist_env_add_back(&head_list, list_elem);
		i++;
	}
	retour = __ft_calloc_env(sizeof(t_lst_env *));
	*retour = head_list;
	return (retour);
}
