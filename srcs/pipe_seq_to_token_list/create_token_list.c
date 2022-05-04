/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 13:57:48 by rpottier         ###   ########.fr       */
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
//		printf("--------------------\n");
//		print_char_two_dim_array(space_split);
//		printf("--------------------\n");
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


char	*clean_quote(char *token_str)
{
	int i;
	int j;
	int	index_dquote;
	char	*str_without_extra_quote;

	str_without_extra_quote = __ft_calloc(sizeof(char) * (ft_strlen(token_str) + 1));
	i = 0;
	j = 0;
	while (token_str[i])
	{
		if (is_quote(token_str[i]))
		{
			if (is_double_quote(token_str[i]))
			{
				i++;
				while (token_str[i] && !is_double_quote(token_str[i]))
				{
					str_without_extra_quote[j] = token_str[i];
					j++;
					i++;
				}
			}
			else if (is_simple_quote(token_str[i]))
			{
				i++;
				while (token_str[i] && !is_simple_quote(token_str[i]))
				{
					str_without_extra_quote[j] = token_str[i];
					j++;
					i++;
				}
			}
		}
		else
		{
			str_without_extra_quote[j] = token_str[i];
			j++;
			i++;
		}
	}
	return (str_without_extra_quote);
}
t_lst_token	*create_token(char	*space_split)
{
	t_lst_token	*token;
	char 	*dup;
	printf("HERE: |%s|\n", space_split);
	token = __ft_calloc(sizeof(t_lst_token));
	dup = dup_without_extra_space(space_split);
	token->type = find_token_type(space_split);
	if (token->type == TOK_SINGLE_QUOTE || token->type == TOK_DOUBLE_QUOTE)
		token->str = clean_quote(dup);
	else
		token->str = dup;
	printf("token->str = [%s]\n", token->str);
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
	int		begun_with_quote = 0;

	i = 0;
	while (is_space(str[i]))
		i++;
/*	while (is_quote(str[i]))
	{
		begun_with_quote = 1;
		i++;
	}*/
	end = ft_strlen(str) - 1;
	while (is_space(str[end]))
		end--;

//	printf("i = [%d] end = [%d]\n", i, end);
/*	while (begun_with_quote && is_quote(str[end]))
		end--;*/
	dup = __ft_calloc(sizeof(char) * ((end - i) + 2));
	j = 0;
	while (str[i + j] && ((i + j) <= end))
	{
//		printf("TEMOIN %d\n", j);
		dup[j] = str[i + j];
		j++;
	}

//	printf("DUP= [%s]\n", dup);
	return (dup);
}


char	*dup_without_extra_space_leave_one_space(char *str)
{
	char	*dup;
	int		end;
	int		i;
	int		j;
	int		begun_with_quote = 0;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (i > 1)
		i = i - 1;
/*	while (is_quote(str[i]))
	{
		begun_with_quote = 1;
		i++;
	}*/
	end = ft_strlen(str) - 1;
	int save = end;
	while (is_space(str[end]))
		end--;
	if ((save - end) > 1)
		end++;
//	printf("i = [%d] end = [%d]\n", i, end);
/*	while (begun_with_quote && is_quote(str[end]))
		end--;*/
	dup = __ft_calloc(sizeof(char) * ((end - i) + 2));
	j = 0;
	while (str[i + j] && ((i + j) <= end))
	{
//		printf("TEMOIN %d\n", j);
		dup[j] = str[i + j];
		j++;
	}

//	printf("DUP= [%s]\n", dup);
	return (dup);
}