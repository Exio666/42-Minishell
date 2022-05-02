/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:36:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/02 19:47:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_wildcard(char *str, t_wildcard *quote, int j)
{
	if (str[j] == '\'' && quote->wild_in_double_quote == 0)
	{
		if (quote->wild_in_simple_quote == 1)
			quote->wild_in_simple_quote = 0;
		else
			quote->str_in_simple_quote = 1;
		return (quote_wildcard(str, quote, j));
	}
	else if (str[j] == '\'' && quote->wild_in_simple_quote == 0)
	{
		if (quote->wild_in_double_quote == 1)
			quote->wild_in_double_quote = 0;
		else
			quote->wild_in_double_quote = 1;
		return (quote_wildcard(str, quote, j));
	}
	else
		return (j);
}

int	wild_quote_name(char c, t_wildcard *quote)
{
	if (c == '\'' && quote->str_in_double_quote == 0)
	{
		if (quote->str_in_simple_quote == 1)
			quote->str_in_simple_quote = 0;
		else
			quote->str_in_simple_quote = 1;
	}
	else if (c == '\'' && quote->str_in_simple_quote == 0)
	{
		if (quote->str_in_double_quote == 1)
			quote->str_in_double_quote = 0;
		else
			quote->str_in_double_quote = 1;
	}
	else
		return (0);
}

int	compare_name_and_wildcard(char *name, char *wildcard_str, t_wildcard *quote)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	j = 0;
	while (wildcard_str[j] == '*')
		j++;
	if (wildcard_str[j] == '\0')
		return (1);
	while (name[i] && wildcard_str[j])
	{
		if (!wild_quote_name(name[i], quote))
			i++;
		else
		{
			j = quote_wilcard(wildcard_str, quote, j);
			if (wildcard_str[j] == '*' && quote->wild_in_double_quote == 0
				&& quote->wild_in_simple_quote == 0)
				return (compare_name_and_wildcard(&name[i], &wildcard_str[j]));
			if (wildcard_str[j] == name[i])
				j++;
			else
				j = 0;
			j = quote_wildcard(wildcard_str, j, quote);
		}
	}
	if (wildcard_str[j] == '\0')
		return (1);
	return (0);
}

char	*ft_wildcard(char *wildcard_str)
{
	DIR				*fd_dir;
	struct dirent	*dir;
	char			*retour;
	t_wildcard		quote;

	retour = NULL;
	quote.str_in_double_quote = 0;
	quote.str_in_simple_quote = 0;
	quote.wild_in_double_quote = 0;
	quote.wild_in_simple_quote = 0;
	fd_dir = opendir(".");
	if (fd_dir == NULL)
		return (str);
	while (1)
	{
		dir = readdir(fd_dir);
		if (dir == NULL)
			break ;
		if (compare_name_and_wildcard(dir->name, wildcard_str, &quote))
		{
			if (retour == NULL)
				retour = ft_strdup(dir->name);
			else
				retour = ft_strjoin(retour, dir->name);
		}
		free(d);
	}
	if (!retour)
		return (str);
	return (retour);
}
