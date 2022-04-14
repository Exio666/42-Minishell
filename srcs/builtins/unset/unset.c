/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:33:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 10:45:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **str, t_lst_env **lst_env)
{
	/*int			i;
	t_lst_env	*tmp;

	i = 0;
	tmp = *lst_env;
	while (str[i])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->name, str[i]) == 0)
			{
				if (tmp->prev)
					tmp->prev->next = tmp->next;
				else
					*lst_env = tmp->next;
				if (tmp->next)
					tmp->next->prev = tmp->prev;	
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}*/
	return (0);
}
