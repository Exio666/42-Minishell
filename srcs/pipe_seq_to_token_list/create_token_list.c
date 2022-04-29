/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 16:44:22 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token	*create_token_list(char **split)
{
	int		i;
	int		j;
	char	**space_split;
	t_lst_token	*lst;

	lst = NULL;
	i = 0;
	while (split[i])
	{
		space_split = split_pipe_by_space(split[i]);
		j = 0;
		while (space_split[j])
		{
			ft_lstadd_back_token(&lst, create_token(space_split[j]));
			j++;
		}
		i++;
	}
	return (lst);
}

t_lst_token	*create_token(char	*space_split)
{
	t_lst_token	*token;

//	printf("HERE: |%s|\n", space_split);
	token = __ft_calloc(sizeof(t_lst_token));
	token->str = dup_without_extra_space(space_split);
	token->type = find_token_type(space_split);
	token->next = NULL;
	return (token);
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

/*
t_lst_token *ft_lstnew_calloc(void *content)
{
	t_lst_token	*new;
	t_lst_token	*content_2;

	content_2 = content;
	new = __ft_calloc(sizeof(t_lst_token));
	if (!new)
		return (NULL);
	new->str = content_2->str;
	new->type = content_2->type;
	new->next = NULL;
	return (new);
}*/

t_lst_token	*ft_lstlast_token(t_lst_token *token)
{
	t_lst_token	*last;

	last = token;
	if (!last)
		return (token);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
void	ft_lstadd_back_token(t_lst_token **alst, t_lst_token *new)
{
	t_lst_token	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast_token(*alst);
	tmp->next = new;
}
/*
void	add_token_to_lst(t_lst_token **lst, t_lst_token *token)
{
	t_lst_token	*elem;

	elem = ft_lstnew_calloc(token);
	ft_lstadd_back(lst, elem);
}
*/
char	*dup_without_extra_space(char *str)
{
	char	*dup;
	int		end;
	int		i;
	int		j;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (is_quote(str[i]))
		i++;
	end = ft_strlen(str) - 1;
	while (is_space(str[end]))
		end--;
	while (is_quote(str[end]))
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
