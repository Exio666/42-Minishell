/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destuct_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:33:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 18:03:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destuct_heredoc(t_btree	**tab, int nb_heredoc)
{
	t_lst_token	*tmp;
	int			nb;
	int			destruct_heredoc;

	nb = 0;
	destruct_heredoc = 0;
	while (tab[nb] && destruct_heredoc < nb_heredoc)
	{
		tmp = tab[nb]->token;
		while (tmp && destruct_heredoc < nb_heredoc)
		{
			if (tmp->type == TOK_HEREDOC)
			{
				tmp = tmp->next;
				unlink(tmp->str);
				destruct_heredoc++;
			}
			tmp = tmp->next;
		}
		nb++;
	}
}
