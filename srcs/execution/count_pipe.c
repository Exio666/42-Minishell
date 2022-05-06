/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:27:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 14:33:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(t_lst_token *token)
{
	t_lst_token	*tmp;
	int			count;

	count = 1;
	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOK_PIPE)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
