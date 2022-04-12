/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:14:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/12 13:14:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lst_env(t_lst_env	*list_elem)
{
	while (list_elem)
	{
		printf("%s = %s\n", list_elem->name, list_elem->content);
		list_elem = list_elem->next;
	}
}
