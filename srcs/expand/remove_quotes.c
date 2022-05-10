/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:07:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 13:29:24 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_quote	*create_quote_index(int open_quote_index, int close_quote_index)
{
	t_lst_quote	*lst_quote;

	lst_quote = __ft_calloc(sizeof(t_lst_quote));
	lst_quote->index.open = open_quote_index;
	lst_quote->index.close = close_quote_index;
	lst_quote->next = NULL;
	return (lst_quote);
}

t_lst_quote	*ft_lstquote_last(t_lst_quote *lst)
{
	t_lst_quote	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_lstquote_add_back(t_lst_quote **alst, t_lst_quote *new)
{
	t_lst_quote	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstquote_last(*alst);
	tmp->next = new;
}

int	is_in_lst_quote(int index, t_lst_quote *lst_quote)
{
	while (lst_quote)
	{
		if (index == lst_quote->index.open || index == lst_quote->index.close)
			return (1);
		lst_quote = lst_quote->next;
	}
	return (0);
}

char	*remove_quotes(t_lst_token *token, t_lst_quote *lst_quote)
{
	char	*token_with_quotes_removed;
	int		token_len;
	int		index;
	int		j;
	int		space_to_split = FALSE;
	index = 0;
	j = 0;
	token_len = ft_strlen(token->str);
	token_with_quotes_removed = __ft_calloc(sizeof(char) * (token_len + 1));
	token->in_quotes = __ft_calloc(sizeof(int) * (token_len + 1));
	while (token->str[index])
	{
		if (!is_in_lst_quote(index, lst_quote))
		{
			token_with_quotes_removed[j] = token->str[index];
			token->in_quotes[j] = space_to_split;
			j++;
		}
		else
		{
			if (space_to_split == FALSE)
				space_to_split = TRUE;
			else if (space_to_split == TRUE)
				space_to_split = FALSE;
		}
		index++;
	}
//	printf("%s\n", token_with_quotes_removed);
//	for (int i = 0; i < ft_strlen(token_with_quotes_removed); i++)
//		printf("%d", token->in_quotes[i]);
//	printf("\n");
	return (token_with_quotes_removed);
}
