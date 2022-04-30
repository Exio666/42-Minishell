/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/30 15:02:32 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect_token(t_type_token token_type)
{
	if (token_type == TOK_REDIRECT_IN)
		return (TRUE);
	else if (token_type == TOK_REDIRECT_OUT)
		return (TRUE);
	else if (token_type == TOK_REDIRECT_OUT_APPEND)
		return (TRUE);
	else
		return (FALSE);
}

int	is_heredoc_token(t_type_token token_type)
{
	if (token_type == TOK_HEREDOC)
		return (TRUE);
	else
		return (FALSE);
}

int	count_tok_word(t_lst_token *token)
{
	int	count;

	count = 0;
	while (token && token->type == TOK_WORD)
	{
		count++;
		token = token->next;
	}
	return (count);
}

t_lst_token	*skip_two_token(t_lst_token *token)
{
	token = token->next;
	token = token->next;
	return (token);
}
