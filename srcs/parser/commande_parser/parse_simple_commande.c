/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_commande.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:07:48 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/08 12:53:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int epandeur(char *commande)
{
	int index;
	int level_quote;
	
	index = 0;
	level_quote = 0;
	while (commande[index])
	{
		index = jump_caracters(pipe_sequence, "\'$", index, 1);
		if (commande[index] == "\'")
			skip_quote(commande, &index);
	}
}

t_list	**parse_commande(char *commande)
{
	epandeur(commande);
	commande_quote_treatment(commande);
}