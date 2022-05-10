/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_caracters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:20:50 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 21:21:20 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	jump_caracters(char *str, char *caracters, int index, int step)
{
	while (str[index] && index >= 0 && step != 0)
	{
		if (strchr(caracters, str[index]))
			return (index);
		index += step;
	}
	return (-1);
}

int	is_quote(char c)
{
	if (is_simple_quote(c) || is_double_quote(c))
		return (TRUE);
	else
		return (FALSE);
}

int	is_simple_quote(char c)
{
	if (c == '\'')
		return (TRUE);
	else
		return (FALSE);
}

int	is_double_quote(char c)
{
	if (c == '\"')
		return (TRUE);
	else
		return (FALSE);
}

int	skip_quote(char *commande, int *i)
{
	if (commande[*i] == '\'')
	{
		*i = jump_caracters(commande, "\'", *i + 1, 1);
		if (*i != -1)
			(*i)++;
	}
	else if (commande[*i] == '\"')
	{
		*i = give_next_character(commande, *i + 1, '\"');
		if (*i != -1)
			(*i)++;
	}
	return (*i);
}
