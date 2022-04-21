/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:57:36 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 12:59:46 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dollar_token(char *str)
{
	if (*str == '$')
		return (TRUE);
	return (FALSE);
}

int	is_single_quote_token(char *str)
{
	if (*str == '\'')
		return (TRUE);
	return (FALSE);
}

int	is_double_quote_token(char *str)
{
	if (*str == '\"')
		return (TRUE);
	return (FALSE);
}
