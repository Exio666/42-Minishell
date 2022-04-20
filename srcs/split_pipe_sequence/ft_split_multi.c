/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/20 06:33:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----- version | < > -----*/

int	is_separator(char c, char *separator)
{
	int	i;

	i = 0;
	while (separator[i])
	{
		if (c == separator[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(char *str, char *sep)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_separator(str[i], sep))
			i++;
		if (str[i] && !is_separator(str[i], sep))
			nb_word++;
		while (str[i] && !is_separator(str[i], sep))
		{
			pipe_skip_quote(str, &i);
			i++;
		}
	}
	return (nb_word);
}

static int	word_len(char *str, char *sep)
{
	int	length;

	length = 0;
	while (str[length] && !is_separator(str[length], sep))
	{
		if (is_quote(str[length]) || is_double_quote(str[length]))
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
	while (s[i] && i < word_len)
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**ft_split_pipe_seq(char *s, char *sep)
{
	int		i;
	int		k;
	char	**split;
	int		nb_word;

	if (!s)
		return (NULL);
	nb_word = (count_word(s, sep) * 2) - 1;
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	i = 0;
	k = -1;
	while (s[i] && ++k < nb_word)
	{
		while (s[i] && is_separator(s[i], sep))
			i++;
		split[k] = insert_word(word_len(&s[i], sep), &s[i]);
		if ((k + 1) < nb_word)
			split[++k] = insert_token_separator(&s[i], sep);
		while (s[i] && !is_separator(s[i], sep))
		{
			pipe_skip_quote(s, &i);
			i++;
		}
	}
	return (split);
}
