/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:02:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/04 17:05:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	give_next_character(char *str, int start, char c)
{
	while (str[start])
	{
		if (str[start] == c)
			return (start);
		start++;
	}
	return (start);
}

int	check_error(t_checker *check, char *str)
{
	check->error = FALSE;
	check->str = str;
	return (0);
}

void	init_struct_checker(t_checker *check)
{
	check->error = FALSE;
	check->index = 0;
	check->str = NULL;
	check->par_lvl = 0;
}

int	primary_checker(char *commande)
{
	t_checker	check;

	i = 0;
	init_struct_checker(&check);
	if (quote_parenthise_checker(commande, &check))
	{
		check.index = 0;
		and_or_pipe_checker(commande, &check);
	}
	if (check.error == FALSE)
		printf("%s\n", check.str);
	return (check.error);
}

/*
int main()
{
	char *commande;

	commande = "";
	if(primary_checker() == TRUE)
		printf("The checker say 'commande is good'");
	else
		printf("The checker say 'commande is bad'");
}*/