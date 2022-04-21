/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:15:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char	*space_split)
{
	t_token	*token;

	token = __ft_calloc(sizeof(t_token));
	token->str = dup_without_extra_space(space_split);
	token->type = find_token_type(space_split);
	return (token);
}

t_list	*create_token_list(char **split)
{
	int		i;
	int		j;
	char	**space_split;
	t_list	*lst;

	lst = NULL;
	i = 0;
	while (split[i])
	{
		space_split = ft_split_pipe_by_space(split[i], " ");
		j = 0;
		while (space_split[j])
		{
			add_token_to_lst(&lst, create_token(space_split[j]));
			j++;
		}
		i++;
	}
	return (lst);
}

int	find_token_type(char *str)
{
	if (is_here_doc_token(str))
		return (TOK_HEREDOC);
	else if (is_redirect_in_token(str))
		return (TOK_REDIRECT_IN);
	else if (is_redirect_out_append_token(str))
		return (TOK_REDIRECT_OUT_APPEND);
	else if (is_redirect_out_token(str))
		return (TOK_REDIRECT_OUT);
	else if (is_pipe_token(str))
		return (TOK_PIPE);
	else if (is_single_quote_token(str))
		return (TOK_SINGLE_QUOTE);
	else if (is_double_quote_token(str))
		return (TOK_DOUBLE_QUOTE);
	else
		return (TOK_WORD);
}

void	add_token_to_lst(t_list **lst, t_token *token)
{
	t_list	*elem;

	elem = ft_lstnew(token);
	ft_lstadd_back(lst, elem);
}

char	*dup_without_extra_space(char *str)
{
	char	*dup;
	int		end;
	int		i;
	int		j;

	i = 0;
	while (is_space(str[i]))
		i++;
	end = ft_strlen(&str[i]) - 1;
	while (is_space(str[end]))
		end--;
	dup = __ft_calloc(sizeof(char) * ((end - i) + 2));
	j = 0;
	while (str[i + j] && (i + j <= end))
	{
		dup[j] = str[i + j];
		j++;
	}
	return (dup);
}
