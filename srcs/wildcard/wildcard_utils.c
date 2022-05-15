/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:14:16 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 20:14:09 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_an_asterix_out_of_quotes(t_lst_token *token)
{
	int	i;

	i = 0;
	if (token && token->type == TOK_WORD)
	{
		while (token->str[i])
		{
			if (is_wildcard(token->str[i]) && token->in_quotes[i] == FALSE)
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

int	end_of_both_str_reached(char *pattern, char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int	characters_are_matching(char c1, char c2)
{
	if (c1 == c2)
		return (TRUE);
	else
		return (FALSE);
}

int	str_is_matching_pattern(char *pattern, char *str)
{
	if (end_of_both_str_reached(pattern, str))
		return (TRUE);
	if (is_wildcard(*pattern) && *(pattern + 1) != '\0' && *str == '\0')
		return (FALSE);
	if (characters_are_matching(*pattern, *str))
		return (str_is_matching_pattern(pattern + 1, str + 1));
	if (is_wildcard(*pattern))
		return (str_is_matching_pattern(pattern + 1, str)
			|| str_is_matching_pattern(pattern, str + 1));
	return (FALSE);
}
