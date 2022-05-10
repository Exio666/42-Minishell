/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:24:41 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 08:24:56 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lstquote(t_lst_quote *lst_quote)
{
	t_lst_quote	*tmp;

	tmp = lst_quote;
	while (tmp)
	{
		printf("(%d) (%d)\n", tmp->index.open, tmp->index.close);
		tmp = tmp->next;
	}
}
