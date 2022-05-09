/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:33:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 17:49:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destuct_heredoc(t_lst_token *token)
{
	t_lst_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOK_HEREDOC)
		{
			tmp = tmp->next;
			unlink(tmp->str);
		}
		tmp = tmp->next;
	}
}
