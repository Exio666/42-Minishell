/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 15:08:59 by rpottier         ###   ########.fr       */
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
		while (token->str[i] && is_space(token->str[i])
			&& token->in_quotes[i] == FALSE)
			i++;
		if (token->str[i] && (!is_space(token->str[i])
				|| (is_space(token->str[i]) && token->in_quotes[i] == TRUE)))
			nb_word++;
		while (token->str[i] && (!is_space(token->str[i])
				|| (is_space(token->str[i]) && token->in_quotes[i] == TRUE)))
		{
			if (is_quote(token->str[i]))
				pipe_skip_quote(token->str, &i);
			else
				i++;
		}
	}
	return (nb_word);
}

static int	word_len(int *in_quotes, char *str)
{
	int	length;

	length = 0;
	while (str[length] && (!is_space(str[length])
			|| (is_space(str[length]) && in_quotes[length] == TRUE)))
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

t_split *split_post_expand(t_lst_token *token)
{
	int		i;
	int		k;
	t_split *split;
	int		nb_word;

	if (!token->str)
		return (NULL);
	nb_word = count_word(token);
	split = __ft_calloc(sizeof(t_split));
	split->split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	i = 0;
	k = -1;
	while (token->str[i] && ++k < nb_word)
	{
		skip_space_out_of_quotes(token, &i);
		split->split[k] = insert_word(word_len(&token->in_quotes[i], &token->str[i]), &token->str[i]);
		while (token->str[i] && space_is_separator(token, i))
		{
			if (is_quote(token->str[i]))
				pipe_skip_quote(token->str, &i);
			else
				i++;
		}
	}
	split->size_2d_array = ft_size_2d_array(split->split);
	return (split);
}
