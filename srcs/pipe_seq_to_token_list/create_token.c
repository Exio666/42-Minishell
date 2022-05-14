/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:12:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 14:16:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token	*create_token(char	*space_split)
{
	t_lst_token	*token;

	token = __ft_calloc(sizeof(t_lst_token));
	token->str = dup_without_extra_space(space_split);
	token->type = find_token_type(space_split);
	token->in_quotes = NULL;
	token->lst_quote = NULL;
	token->next = NULL;
	return (token);
}

t_lst_token	*create_token_for_split(char	*space_split, int *in_quotes)
{
	t_lst_token	*token;

	token = __ft_calloc(sizeof(t_lst_token));
	token->str = dup_without_extra_space(space_split);
	token->in_quotes = in_quotes;
	token->type = find_token_type(space_split);
	token->in_quotes = NULL;
	token->lst_quote = NULL;
	token->next = NULL;
	return (token);
}

t_lst_token	*create_token_expand(char	*space_split)
{
	t_lst_token	*token;

	token = __ft_calloc(sizeof(t_lst_token));
	token->str = dup_without_extra_space(space_split);
	token->type = find_token_type(space_split);
	token->next = NULL;
	return (token);
}

int	find_token_type(char *str)
{
	if (is_here_doc_token(str))
		return (TOK_HEREDOC);
	else if (is_redirect_in_token(str))
		return (TOK_REDIRECT_IN);
	else if (is_redirect_out_append_token(str))
		return (TOK_REDIRECT_OUT_APPEND);
	else if (is_redirect_out_token(str))
		return (TOK_REDIRECT_OUT);
	else if (is_pipe_token(str))
		return (TOK_PIPE);
	else
		return (TOK_WORD);
}

char	*dup_without_extra_space(char *str)
{
	char	*dup;
	int		end;
	int		i;
	int		j;

	i = 0;
	while (is_space(str[i]))
		i++;
	end = ft_strlen(str) - 1;
	while (is_space(str[end]))
		end--;
	dup = __ft_calloc(sizeof(char) * ((end - i) + 2));
	j = 0;
	while (str[i + j] && (i + j <= end))
	{
		dup[j] = str[i + j];
		j++;
	}
	return (dup);
}
