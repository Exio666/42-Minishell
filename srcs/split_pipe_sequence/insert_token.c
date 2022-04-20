/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 06:03:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/20 06:07:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*insert_token_separator(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_separator(str[i], sep))
	{
		if (is_quote(str[i]))
			pipe_skip_quote(str, &i);
		else
			i++;
	}
	if (str[i] == '|')
		return (insert_token_pipe());
	else if (str[i] == '<')
		return (insert_token_redirect_in());
	else if (str[i] == '>')
		return (insert_token_redirect_out());
}

char	*insert_token_redirect_in(void)
{
	return (ft_strdup("<"));
}

char	*insert_token_redirect_out(void)
{
	return (ft_strdup(">"));
}

char	*insert_token_pipe(void)
{
	return (ft_strdup("|"));
}
