/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/15 13:10:25 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----- version | < > << >> -----*/

static int	count_word(char *str, char *sep)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (is_white_space(*str))
		str++;
	while (str[i])
	{
		if (is_separator(str[i], sep))
			nb_word++;
		while (str[i] && is_separator(str[i], sep))
			i++;
		if (str[i] && !is_separator(str[i], sep))
			nb_word++;
		while (str[i] && !is_separator(str[i], sep))
		{
			if (is_quote(str[i]))
				pipe_skip_quote(str, &i);
			else
				if (str[i])
					i++;
		}
	}
	return (nb_word);
}

static int	word_len(char *str, char *sep)
{
	int	length;

	length = 0;
	while (is_white_space(*str))
		str++;
	while (str[length] && !is_separator(str[length], sep))
	{
		if (is_quote(str[length]))
			pipe_skip_quote(str, &length);
		else
			length++;
	}
	return (length);
}

static char	*insert_word(int word_len, char *s)
{
	int		i;
	char	*split;

	i = 0;
	split = __ft_calloc(sizeof(char) * (word_len + 1));
	if (!split)
		return (NULL);
	while (is_white_space(*s))
		s++;
	while (s[i] && i < word_len)
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	i--;
	while (is_white_space(split[i]))
	{
		split[i] = '\0';
		i--;
	}
	return (split);
}

void	move_foward_split_by_separator(char *s, int *i)
{
	if (is_quote(s[*i]))
		pipe_skip_quote(s, i);
	else
		(*i)++;
}

char	**split_by_separator(char *s, char *sep)
{
	int		i;
	int		k;
	char	**split;
	int		nb_word;

	nb_word = (count_word(s, sep));
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	i = 0;
	k = -1;
	if (is_separator(s[i], sep))
		split[++k] = insert_token_separator(&s[i], sep);
	while (s[i] && ++k < nb_word)
	{
		while (s[i] && is_separator(s[i], sep))
			i++;
		split[k] = insert_word(word_len(&s[i], sep), &s[i]);
		if ((k + 1) < nb_word)
			split[++k] = insert_token_separator(&s[i], sep);
		while (s[i] && !is_separator(s[i], sep))
			move_foward_split_by_separator(s, &i);
	}
	return (split);
}
