/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:09:11 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 11:16:39 by bsavinel         ###   ########.fr       */
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

int	check_all_pipe_sequence(char *command_line)
{
	t_pipe_sequence	**splited;
	int				i;

	splited = split_all_pipe_sequence(command_line);
	i = 0;
	while (splited[i])
	{
		if (pipe_sequence_checker(splited[i]->str) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
