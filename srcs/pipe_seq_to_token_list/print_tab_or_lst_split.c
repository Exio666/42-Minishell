/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab_or_lst_split.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:59:32 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 21:57:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_split_tab(char **split)
{
	for (int i = 0; split[i]; i++)
		printf("|%s|\n", split[i]);
	printf("--------------------------\n");
}

void	print_split_lst(t_list	*lst)
{
	while (lst)
	{
		t_token *ptr = lst->content;
	//	printf("%-10s - type token ==  %d\n", (char *)ptr->str, ptr->type);
		printf("|%s|\n", (char *)ptr->str);
		lst = lst->next;
	}
}
