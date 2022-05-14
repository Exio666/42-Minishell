/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe_by_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/14 14:10:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_word(char *str)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
			nb_word++;
		while (str[i] && !is_space(str[i]))
		{
			if (is_quote(str[i]))
				pipe_skip_quote(str, &i);
			else
				i++;
		}
	}
	return (nb_word);
}

static int	word_len(char *str)
{
	int	length;

	length = 0;
	while (str[length] && !is_space(str[length]))
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
	while (s[i] && i < word_len)
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**split_pipe_by_space(char *s)
{
	int		i;
	int		k;
	char	**split;
	int		nb_word;

	if (!s)
		return (NULL);
	nb_word = count_word(s);
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	i = 0;
	k = -1;
	while (s[i] && ++k < nb_word)
	{
		while (s[i] && is_space(s[i]))
			i++;
		split[k] = insert_word(word_len(&s[i]), &s[i]);
		while (s[i] && !is_space(s[i]))
		{
			if (is_quote(s[i]))
				pipe_skip_quote(s, &i);
			else
				i++;
		}
	}
	return (split);
}
