/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:05:36 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 11:12:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	and_checker(char *commande, t_checker *check)
{
	int	counter;

	counter = 0;
	while (commande[check->index] == '&')
	{
		counter++;
		check->index++;
	}
	if (counter != 2)
	{
		check->error = TRUE;
		check->str = S_ERROR_UNEX_TOK_AND;
	}
}

void	or_checker(char *commande, t_checker *check)
{
	int	counter;

	counter = 0;
	while (commande[check->index] == '|')
	{
		counter++;
		check->index++;
	}
	if (counter > 2)
	{
		check->error = TRUE;
		check->str = S_ERROR_UNEX_TOK_OR;
	}
}

int	and_or_pipe_checker(char *commande, t_checker *check)
{
	while (check->index != -1 && commande[check->index])
	{
		if (commande[check->index] == '&')
			and_checker(commande, check);
		else if (commande[check->index] == '|')
			or_checker(commande, check);
		if (check->error == TRUE)
			return (0);
		check->index = jump_caracters(commande, "\"\'&|", check->index, 1);
		if (check->index != -1)
			quote_jump(commande, check);
	}
	return (1);
}
