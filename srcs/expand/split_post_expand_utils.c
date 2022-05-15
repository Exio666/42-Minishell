/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:37:01 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 20:28:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	space_is_separator(t_lst_token *token, int index)
{
	if ((!is_white_space(token->str[index])
			|| (is_white_space(token->str[index])
				&& token->in_quotes[index] == TRUE)))
		return (TRUE);
	return (FALSE);
}

void	skip_space_out_of_quotes(t_lst_token *token, int *index)
{
	while (token->str[*index] && is_white_space(token->str[*index])
		&& token->in_quotes[*index] == FALSE)
		(*index)++;
}
