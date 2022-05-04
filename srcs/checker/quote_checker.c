/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:04:44 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 13:31:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_jump(char *commande, t_checker *check)
{
	if (commande[check->index] == '\'')
	{
		check->index = jump_caracters(commande, "\'", check->index + 1, 1);
		if (check->index != -1)
			check->index++;
		else
			return (0);
	}
	else if (commande[check->index] == '\"')
	{
		check->index = give_next_character(commande, check->index + 1, '\"');
		if (check->index != -1)
			check->index++;
		else
			return (0);
	}
	return (1);
}

int	quote_parenthise_checker(char *commande, t_checker *check)
{
	char	tmp;

	while (check->index != -1 && commande[check->index])
	{
		if (commande[check->index] == '(')
			check->par_lvl++;
		if (commande[check->index] == ')')
		{
			if (check->par_lvl <= 0)
				return (check_error(check, S_ERROR_NP_CLOSE_PAR));
			check->par_lvl--;
		}
		tmp = commande[check->index];
		if (check->index == -1 || quote_jump(commande, check) == 0)
		{
			if (tmp == '\'')
				return (check_error(check, S_ERROR_M_QUOTE));
			else if (tmp == '\"')
				return (check_error(check, S_ERROR_M_DQUOTE));
		}
		check->index = jump_caracters(commande, "\"\'()", check->index + 1, 1);
	}
	if (check->par_lvl != 0)
		return (check_error(check, S_ERROR_M_OPEN_PAR));
	return (1);
}
