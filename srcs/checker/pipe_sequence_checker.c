/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:11 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 19:14:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_no_whitespace(char *commande)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (commande[i])
	{
		i++;
		if (!ft_iswhitespace(commande[i]))
			len++;
	}	
	return (len);
}

int	pipe_sequence_checker(char *commande)
{
	t_checker	check;

	init_struct_checker(&check);
	if (len_no_whitespace(commande) == 0)
	{
		check.error = TRUE;
		check.str = S_ERROR_MISSING_COMMANDE;
	}
	if (check.error == FALSE)
		redirection_checker(commande, &check);
	if (check.error == TRUE)
		printf("%s\n", check.str);
	return (!check.error);
}
