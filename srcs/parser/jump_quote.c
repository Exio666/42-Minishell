/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:20:50 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/01 16:25:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

int jump_caracters(char *str, char *caracters, int index, int step)
{
	while (str[index] && index >= 0 && step != 0)
	{
		if (strchr(caracters, str[index]))
			return (index);
		index += step;
	}
	return (-1);
}

int is_double_quote(char c)
{
	if (c == '\"')
		return (TRUE);
	else
		return (FALSE);
}

int is_quote(char c)
{
	if (c == '\'')
		return (TRUE);
	else
		return (FALSE);
}