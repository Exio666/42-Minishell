/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:04:44 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/11 16:14:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_jump(char *commande, t_checker *check)
{
	if (commande[check->index] == '\'')
	{
		check->index = jump_caracters(commande, "\'", check->index + 1, 1);
		if (check->index == -1)
			return (0);
	}
	else if (commande[check->index] == '\"')
	{
		check->index = jump_caracters(commande, "\"", check->index + 1, 1);
		if (check->index == -1)
			return (0);
	}
	return (1);
}

void	quote_parenthise_checker_next_char(char *commande, t_checker *check)
{
	if (commande[check->index] && check->index != -1)
		check->index = jump_caracters(commande, "\"\'()", check->index + 1, 1);
}

int	check_len_in_parenthise(char *comande, t_checker *check)
{
	int i;
	int len;

	check->par_lvl++;
	len = -1;
	i = check->index;
	while (comande[i] && comande[i] != ')')
	{
		if (!ft_iswhitespace(comande[i]))
			len++;
		i++;
	}
	if (len == 0 && comande[i] == ')')
		return (0);
	return (1);
}

int	quote_error(char tmp, t_checker *check)
{
	if (tmp == '\'')
		return (check_error(check, S_ERROR_M_QUOTE));
	else if (tmp == '\"')
		return (check_error(check, S_ERROR_M_DQUOTE));
	return (0);
}

int	quote_parenthise_checker(char *commande, t_checker *check)
{
	char	tmp;

	while (check->index != -1 && commande[check->index])
	{
		if (commande[check->index] == '(')
			if (!check_len_in_parenthise(commande, check))
				return (check_error(check, S_ERROR_CMD_PARENTHESE));
		if (commande[check->index] == ')')
		{
			if (check->par_lvl <= 0)
				return (check_error(check, S_ERROR_NP_CLOSE_PAR));
			check->par_lvl--;
		}
		tmp = commande[check->index];
		if (quote_jump(commande, check) == 0
			&& (tmp == '\'' || tmp == '\"'))
			return (quote_error(tmp, check));
		quote_parenthise_checker_next_char(commande, check);
	}
	if (check->par_lvl != 0)
		return (check_error(check, S_ERROR_M_OPEN_PAR));
	return (1);
}
