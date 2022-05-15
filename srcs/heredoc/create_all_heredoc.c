/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:30:36 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 18:05:45 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_tab_token(t_btree **tab, int size)
{
	t_btree	*temp;
	int		x;
	int		y;
	int		z;

	x = 0;
	while (x < size)
	{
		y = 0;
		z = 1;
		while (y < size - 1)
		{
			if (tab[y]->pipe_seq->index > tab[z]->pipe_seq->index)
			{
				temp = tab[y];
				tab[y] = tab[z];
				tab[z] = temp;
			}
			y++;
			z++;
		}
		x++;
	}
}

void	tab_of_pipe_sequense_token(t_btree *root, t_btree **tab, int *nb)
{
	if (!root)
		return ;
	tab_of_pipe_sequense_token(root->left, tab, nb);
	if (root->token)
	{
		tab[*nb] = root;
		(*nb)++;
	}
	tab_of_pipe_sequense_token(root->right, tab, nb);
}

int	create_heredoc_in_pipe_sequence(t_lst_token *token)
{
	t_lst_token	*tmp;
	int			nb_heredoc;

	tmp = token;
	nb_heredoc = 0;
	while (tmp && g_exit_status != 386)
	{
		if (tmp->type == TOK_HEREDOC && g_exit_status != 386)
		{
			tmp = tmp->next;
			tmp->str = heredoc_create(tmp->str);
			nb_heredoc++;
		}
		tmp = tmp->next;
	}
	return (nb_heredoc);
}

void	create_all_heredoc(t_btree	**root, char *commande)
{
	t_btree	*extract;
	t_btree	**tab;
	int		nb;
	int		nb_heredoc;

	extract = *root;
	nb = 0;
	nb_heredoc = 0;
	tab = __ft_calloc(sizeof(t_btree *) * (count_pipe_sequence(commande) + 1));
	tab_of_pipe_sequense_token(extract, tab, &nb);
	tab[nb] = NULL;
	sort_tab_token(tab, count_pipe_sequence(commande));
	nb = 0;
	signal(SIGINT, &handler_sigint_empty);
	while (tab[nb])
	{
		nb_heredoc += create_heredoc_in_pipe_sequence(tab[nb]->token);
		nb++;
	}
	if (g_exit_status == 386)
		destuct_heredoc(tab, nb_heredoc);
}
