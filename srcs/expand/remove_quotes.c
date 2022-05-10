/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:07:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/11 00:58:05 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_space_to_split(int space_to_split)
{
	if (space_to_split == FALSE)
		return (TRUE);
	else
		return (FALSE);
}

char	*remove_quotes(t_lst_token *token, t_lst_quote *lst_quote)
{
	char	*quotes_removed;
	int		index;
	int		j;
	int		space_to_split;

	space_to_split = FALSE;
	index = 0;
	j = 0;
	quotes_removed = __ft_calloc(sizeof(char) * (ft_strlen(token->str) + 1));
	token->in_quotes = __ft_calloc(sizeof(int) * (ft_strlen(token->str) + 1));
	while (token->str[index])
	{
		if (!is_in_lst_quote(index, lst_quote))
		{
			quotes_removed[j] = token->str[index];
			token->in_quotes[j] = space_to_split;
			j++;
		}
		else
			space_to_split = set_space_to_split(space_to_split);
		index++;
	}
	return (quotes_removed);
}

//	printf("%s\n", token_with_quotes_removed);
//	for (int i = 0; i < ft_strlen(token_with_quotes_removed); i++)
//		printf("%d", token->in_quotes[i]);
//	printf("\n");