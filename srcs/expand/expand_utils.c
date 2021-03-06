/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:21:36 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/20 23:43:24 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token	*move_to_last_new_token(t_lst_token *token, int nb_token)
{
	int	i;

	i = 0;
	while (token && i < (nb_token - 1))
	{
		token = token->next;
		i++;
	}
	return (token);
}

void	move_foward_expanding_var(int open_quote, char *token_str, int *index)
{
	if (open_quote != -1)
	{
		if (!is_simple_quote(token_str[open_quote]))
			(*index)++;
	}
	else
		(*index)++;
}

/*
void	print_token_str_with_active_char(t_lst_token *token)
{
	for (int i= 0; token->str[i]; i++)
		printf("%c", token->str[i]);
	printf("\n");
	for (int i= 0; token->str[i]; i++)
		printf("%d", token->in_quotes[i]);
	printf("\n");
}
*/