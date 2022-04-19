/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/19 21:11:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----- version | < > -----*/

static int is_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	count_word(char *str, char *sep)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], sep))
			i++;
		if (str[i] && !is_sep(str[i], sep))
			nb_word++;
		while (str[i] && !is_sep(str[i], sep))
		{
			if (is_quote(str[i]))
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
	while (str[length] && !is_sep(str[length], sep))
	{
		if (is_quote(str[length]))
			pipe_skip_quote(str, &length);
		else
			length++;
	}
	return (length);
}

static char	*insert_word(int word_len, char  *s)
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

static char	**free_split(char **split, int k)
{
	while (--k)
		free(split[k]);
	free(split);
	return (NULL);
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

char	*insert_token_separator(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_sep(str[i], sep))
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

char	**ft_split_pipe_seq(char *s, char *sep)
{
	int		i;
	int		k;
	char	**split;
	int		nb_word;

	i = 0;
	k = 0;
	nb_word = (count_word(s, sep) * 2) - 1;
	if (!s)
		return (NULL);
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	if (split == NULL)
		return (NULL);
	while (s[i] && k < nb_word )
	{
		while (s[i] && is_sep(s[i], sep))
			i++;
		split[k] = insert_word(word_len(&s[i], sep), &s[i]);
		if ((k + 1) < nb_word)
		{
			k++;
			split[k] = insert_token_separator(&s[i], sep);
		}
		while (s[i] && !is_sep(s[i], sep))
		{
			if (is_quote(s[i]))
				pipe_skip_quote(s, &i);
			i++;
		}
		k++;
	}
	split[k] = NULL;
	return (split);
}
