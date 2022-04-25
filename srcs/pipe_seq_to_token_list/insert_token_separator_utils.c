/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_token_separator_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:56:36 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:46:35 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*insert_token_heredoc(void)
{
	return (ft_strdup("<<"));
}

char	*insert_token_redirect_in(void)
{
	return (ft_strdup("<"));
}

char	*insert_token_redirect_out_append(void)
{
	return (ft_strdup(">>"));
}

char	*insert_token_redirect_out(void)
{
	return (ft_strdup(">"));
}

char	*insert_token_pipe(void)
{
	return (ft_strdup("|"));
}
