/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/10 13:28:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_word(t_lst_token *token)
{
	int	nb_word;
	int	i;

	nb_word = 0;
	i = 0;
	while (token->str[i])
	{
		while (token->str[i] && is_space(token->str[i]) && token->in_quotes[i] == FALSE)
			i++;
		if (token->str[i] && (!is_space(token->str[i]) || (is_space(token->str[i]) && token->in_quotes[i] == TRUE)))
			nb_word++;
		while (token->str[i] && (!is_space(token->str[i]) || (is_space(token->str[i]) && token->in_quotes[i] == TRUE)))
		{
			if (is_quote(token->str[i]))
				pipe_skip_quote(token->str, &i);
			else
				i++;
		}
	}
//	printf("nb_word = %d\n", nb_word);
	return (nb_word);
}

static int	word_len(int *in_quotes, char *str)
{
	int	length;

	length = 0;

//	printf("str = %s\n", str);
	while (str[length] && (!is_space(str[length]) || (is_space(str[length]) && in_quotes[length] == TRUE)))
	{
		if (is_quote(str[length]))
			pipe_skip_quote(str, &length);
		else
			length++;
	}
//	printf("word len = %d\n", length);
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
//	printf("||%s||\n", split);
	split[i] = '\0';
	return (split);
}

char	**split_post_expand(t_lst_token *token)
{
	int		i;
	int		k;
	char	**split;
	int		nb_word;

	if (!token->str)
		return (NULL);
	nb_word = count_word(token);
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	i = 0;
	k = -1;
	while (token->str[i] && ++k < nb_word)
	{
		while (token->str[i] && is_space(token->str[i]) && token->in_quotes[i] == FALSE)
			i++;
		split[k] = insert_word(word_len(&token->in_quotes[i], &token->str[i]), &token->str[i]);
		while (token->str[i] && (!is_space(token->str[i]) || (is_space(token->str[i]) && token->in_quotes[i] == TRUE)))
		{
			if (is_quote(token->str[i]))
				pipe_skip_quote(token->str, &i);
			else
				i++;
		}
	}
	return (split);
}