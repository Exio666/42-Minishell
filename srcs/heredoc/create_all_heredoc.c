/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:30:36 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/11 17:38:38 by bsavinel         ###   ########.fr       */
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

void	create_heredoc_in_pipe_sequence(t_lst_token *token)
{
	t_lst_token *tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == TOK_HEREDOC)
		{
			tmp = tmp->next;
			tmp->str = heredoc_create(tmp->str);
		}
		tmp = tmp->next;
	}
}

void	create_all_heredoc(t_btree	**root, char *user_input)
{
	t_btree	*extract;
	t_btree	**tab;
	int		nb;

	extract = *root;
	nb = 0;
	tab = __ft_calloc(sizeof(t_btree *) * (count_pipe_sequence(user_input) + 1));
	tab_of_pipe_sequense_token(extract, tab, &nb);
	tab[nb] = NULL;
	sort_tab_token(tab, count_pipe_sequence(user_input));
	nb = 0;
	while (tab[nb])
	{
		create_heredoc_in_pipe_sequence(tab[nb]->token);
		nb++;
	}
}