/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specific_char_funct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:46:16 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 13:50:44 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_logical_op_char(char c)
{
	if (c == '&' || c == '|')
		return (TRUE);
	else
		return (FALSE);
}

int	is_and_symbol(char c)
{
	if (c == '&')
		return (TRUE);
	else
		return (FALSE);
}

int	is_or_symbol(char c)
{
	if (c == '|')
		return (TRUE);
	else
		return (FALSE);
}

int	is_open_parenthesis(char c)
{
	if (c == '(')
		return (TRUE);
	else
		return (FALSE);
}

int	is_close_parenthesis(char c)
{
	if (c == ')')
		return (TRUE);
	else
		return (FALSE);
}
