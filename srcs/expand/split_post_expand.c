/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:01:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/15 21:14:35 by rpottier         ###   ########.fr       */
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
		while (token->str[i] && is_white_space(token->str[i])
			&& token->in_quotes[i] == FALSE)
			i++;
		if (token->str[i] && (!is_white_space(token->str[i])
				|| (is_white_space(token->str[i])
					&& token->in_quotes[i] == TRUE)))
			nb_word++;
		while (token->str[i] && (!is_white_space(token->str[i])
				|| (is_white_space(token->str[i])
					&& token->in_quotes[i] == TRUE)))
		{
			if (is_quote(token->str[i]))
				pipe_skip_quote(token->str, &i);
			else
				i++;
		}
	}
	return (nb_word);
}

static int	ft_word_len(int *in_quotes, char *str)
{
	int	length;

	length = 0;
	while (str[length] && (!is_white_space(str[length])
			|| (is_white_space(str[length]) && in_quotes[length] == TRUE)))
	{
		if (is_quote(str[length]))
			pipe_skip_quote(str, &length);
		else
			length++;
	}
	return (length);
}

static char	*insert_word(int *in_quotes, char *s)
{
	int		word_len;
	int		i;
	char	*split;

	word_len = ft_word_len(in_quotes, s);
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

static int	*insert_in_quotes_info(int *in_quotes, char *s)
{
	int		word_len;
	int		i;
	int		*in_quotes_info;

	word_len = ft_word_len(in_quotes, s);
	i = 0;
	in_quotes_info = __ft_calloc(sizeof(int) * (word_len));
	while (s[i] && i < word_len)
	{
		in_quotes_info[i] = in_quotes[i];
		i++;
	}
	return (in_quotes_info);
}

t_split	*split_post_expand(t_lst_token *token)
{
	int		i;
	int		k;
	t_split	*split;
	int		nb_word;

	if (!token->str)
		return (NULL);
	nb_word = count_word(token);
	split = __ft_calloc(sizeof(t_split));
	split->split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	split->in_quotes = __ft_calloc(sizeof(int *) * (nb_word));
	i = 0;
	k = -1;
	while (token->str[i] && ++k < nb_word)
	{
		skip_space_out_of_quotes(token, &i);
		split->split[k] = insert_word(&token->in_quotes[i], &token->str[i]);
		split->in_quotes[k] = insert_in_quotes_info(&token->in_quotes[i],
				&token->str[i]);
		while (token->str[i] && space_is_separator(token, i))
			move_foward_split_by_separator(token->str, &i);
	}
	split->size_2d_array = ft_size_2d_array(split->split);
	return (split);
}
