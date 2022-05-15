/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:56:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 18:26:56 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_token_list(t_lst_token *token_list)
{
	int			size;
	t_lst_token	*tmp;

	tmp = token_list;
	size = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	sort_array(t_lst_token **array, int size)
{
	int			i;
	int			j;
	t_lst_token	*tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strncmp(array[j]->str, array[j + 1]->str,
					ft_strlen(array[j]->str)) > 0)
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_token_list(t_lst_token **token_list)
{
	t_lst_token	**array;
	t_lst_token	*sorted;
	int			size;
	int			i;

	sorted = NULL;
	size = size_token_list(*token_list);
	array = __ft_calloc(sizeof(t_lst_token *) * (size + 1));
	i = 0;
	while (i < size)
	{
		array[i] = (*token_list);
		*token_list = (*token_list)->next;
		array[i]->next = NULL;
		i++;
	}
	array[i] = NULL;
	sort_array(array, size);
	i = 0;
	while (i < size)
	{
		ft_lstadd_back_token(&sorted, array[i]);
		i++;
	}
	*token_list = sorted;
}
