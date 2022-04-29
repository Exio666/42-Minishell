/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:57:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 14:50:28 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirect_in_token(char *str)
{
	if (*str == '<')
		return (TRUE);
	return (FALSE);
}

int	is_redirect_out_token(char *str)
{
	if (*str == '>')
		return (TRUE);
	return (FALSE);
}

int	is_redirect_out_append_token(char *str)
{
	if (*str == '>' && (*str + 1) == '>')
		return (TRUE);
	return (FALSE);
}

int	is_pipe_token(char *str)
{
	if (*str == '|')
		return (TRUE);
	return (FALSE);
}

int	is_here_doc_token(char *str)
{
	if (*str == '<' && (*(str + 1)) == '<')
		return (TRUE);
	return (FALSE);
}
