/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:21:36 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 08:47:01 by rpottier         ###   ########.fr       */
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

int	in(t_lst_token *token, int index)
{
	int	len;

	if (!token)
		return (FALSE);
	if (!token->str)
		return (FALSE);
	len = ft_strlen(token->str);
	if (index >= 0 && index < len)
		return (TRUE);
	return (FALSE);
}

void	init_expand_all_variable(int *tmp, t_quote_index *quote)
{
	*tmp = -2;
	quote->open = -1;
	quote->close = -1;
}

void	expand_dollar(t_lst_token *token, t_lst_env *env_list, int *i, int *tmp)
{
	*tmp = *i;
	token->str = expand_variable(token->str, i, env_list);
	if (in(token, *i) && is_dollar(token->str[(*i)]) && !token->str[(*i) + 1])
		*tmp = -2;
	else if (in(token, *i) && is_dollar(token->str[*i]) && token->str[(*i) + 1])
		(*i)++;
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