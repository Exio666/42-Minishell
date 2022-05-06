/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:48:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/06 11:35:17 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word_quote(char *token_str)
{
	int nb_word;
	int	i = 0;
	nb_word = 0;
	while (token_str[i])
	{
		if (token_str[i] && is_quote(token_str[i]))
		{
			skip_quote(token_str, &i);
			nb_word++;
		}
		if (token_str[i] && !is_quote(token_str[i]))
		{
			i++;
			nb_word++;
		}		
	}
	return (nb_word);
}

void split_token_by_quote(char *token_str)
{
	int i;
	int nb_word;
	char	**split;
	i = 0;
	int k = 0;
	int word_len;
	nb_word = count_word_quote(token_str);
	printf("nb_word = %d\n",nb_word);
	split = __ft_calloc(sizeof(char *) * (nb_word + 1));
	while (token_str[i] && k < nb_word)
	{
		word_len = 0;
		if (token_str[i] && is_quote(token_str[i]))
		{				
			word_len++;
			while (!is_quote(token_str[++i]))
				word_len++;
			word_len++;
			
		}
		else if (token_str[i] && !is_quote(token_str[i]))
		{
			i++;
			nb_word++;
		}		

	}
}

void split_token_lst_by_quote(t_lst_token *token_lst)
{
//	t_lst_token *token_lst_to_insert;
	t_lst_token *head_lst;
	
	head_lst = token_lst;
	int i = 0;
	while (token_lst)
	{
		while (token_lst->str[i])
		{
			if (is_quote(token_lst->str[i]))
				split_token_by_quote(token_lst->str);
			i++;
		}
		token_lst = token_lst->next;
	}
}

t_lst_token *get_token_list(char	*pipe_sequence)
{
	char		**split;
	t_lst_token	*token_lst;
	
	split = split_by_separator(pipe_sequence, "|<>");
	token_lst = create_token_list(split);
	split_token_lst_by_quote(token_lst);
	return (token_lst);
}
