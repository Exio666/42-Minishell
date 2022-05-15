/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:49:28 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:44:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_wildcard(char c)
{
	if (c == '*')
		return (true);
	else
		return (false);
}

int	is_separator(char c, char *separator)
{
	int	i;

	i = 0;
	while (separator[i])
	{
		if (c == separator[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_dot(char c)
{
	if (c == '.')
		return (TRUE);
	else
		return (FALSE);
}
