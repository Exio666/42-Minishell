/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:51:03 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/03 16:38:34 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token	*find_first_token_cmd(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
	{
		if (token && (is_heredoc_token(token->type) || is_redirect_token(token->type)))
			token = skip_two_token(token);
		if (token && token->type == TOK_WORD)
			return (token);
		if (token)
			token = token->next;
	}
	return (token);
}

t_lst_token	*find_first_token_next_cmd(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
		token = token->next;
	if (!token)
		return (NULL); //no more command
	else
		return (token->next); //considérant que le checker ne laisse pas passer une cmd qui se termine pas un |
}
