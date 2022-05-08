/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:39:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/08 17:37:35 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dollar(char c)
{
	if (c == '$')
		return (TRUE);
	return (FALSE);
}

int	get_var_length(char	*token)
{
	int length;

//	printf("TOKEN = %s\n", token);
	length = 0;
	while (token[length] != '\0' && !is_space(token[length]) && !is_quote(token[length])&& !is_dollar(token[length]))
		length++;
	return (length);
}

char	*get_variable_to_expand_name(char *token)
{
	int var_len;
	char *var_name;
	int i;

	i = 0;
	var_len = get_var_length(token);
	if (var_len == 0)
		return (NULL);
	var_name = __ft_calloc(sizeof(char) * (var_len + 1));
	ft_strlcpy (var_name, token, var_len + 1);
	return (var_name);
}

char *get_var_to_expand_content(char *var_name, t_lst_env *env_list)
{
	while (env_list)
	{
		if (strcmp(var_name, env_list->name) == 0)
			return (env_list->content);
		env_list = env_list->next;
	}
	return (NULL);
}
	
void	insert_var_content_to_token(char **token, char *var_content, int start_index)
{
	int token_len;
	int var_content_len;
	int expanded_token_len;
	int var_len;
	char	*expanded_token;
	//int i = 0;

//	printf("0 token:[%s]\n", *token);
	
	token_len = ft_strlen(*token);
	var_content_len = ft_strlen(var_content);
	expanded_token = __ft_calloc(sizeof(char) * (token_len + var_content_len + 1));
	
	ft_strlcpy(expanded_token, *token, start_index + 1);
//	printf("1 expanded_token: [%s]\n", expanded_token);
	
	ft_strlcat(expanded_token, var_content, (token_len + var_content_len + 1));
//	printf("2 expanded_token: [%s]\n", expanded_token);
	
	
	expanded_token_len = ft_strlen(expanded_token);
	var_len = get_var_length(&(*token)[start_index + 1]);
	token_len = ft_strlen(&(*token)[start_index + var_len]);
	
	ft_strlcat(expanded_token, &(*token)[start_index + var_len + 1], (expanded_token_len + token_len + 1));
//	printf("3 expanded_token: [%s]\n", expanded_token);
	
//	free(*token);
	*token = expanded_token;
}

typedef struct s_quote_index
{
	int open;
	int close;	
} t_quote_index;

typedef struct s_lst_quote
{
	struct s_lst_quote	*next;
	t_quote_index				index;
	
}	t_lst_quote;

t_lst_quote *create_quote_index(int open_quote_index, int close_quote_index)
{
	t_lst_quote *lst_quote;

	lst_quote = __ft_calloc(sizeof(t_lst_quote));
	lst_quote->index.open = open_quote_index;
	lst_quote->index.close = close_quote_index;
	lst_quote->next = NULL;
	return (lst_quote);
	
}
t_lst_quote	*ft_lstquote_last(t_lst_quote *lst)
{
	t_lst_quote	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
void	ft_lstquote_add_back(t_lst_quote **alst, t_lst_quote *new)
{
	t_lst_quote	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstquote_last(*alst);
	tmp->next = new;
}

void	print_lstquote(t_lst_quote *lst_quote)
{
	t_lst_quote *tmp;

	tmp = lst_quote;
	while (tmp)
	{
		printf("(%d) (%d)\n", tmp->index.open, tmp->index.close);
		tmp = tmp->next;
	}
}

typedef struct s_count_quote
{
	int	double_quote;
	int simple_quote;
}	t_count_quote;

t_count_quote	*count_quote_couple(char *token)
{
	t_count_quote *nb_couple;
	int i;

	i = 0;
	nb_couple = malloc(sizeof(nb_couple));
	nb_couple->double_quote = 0;
	nb_couple->simple_quote = 0;
	while (token[i])
	{
		if (is_quote(token[i]))
		{
			if(is_simple_quote(token[i]))
				nb_couple->simple_quote++;
			else
				nb_couple->double_quote++;
		}
		i++;
	}
	nb_couple->simple_quote /= 2;
	nb_couple->double_quote /= 2;
	return (nb_couple);
}

int is_in_lst_quote(int index, t_lst_quote *lst_quote)
{
	while (lst_quote)
	{
		if (index == lst_quote->index.open || index == lst_quote->index.close)
			return (1);
		lst_quote = lst_quote->next;
	}
	return (0);
}

char	*remove_quotes(char *token, t_lst_quote *lst_quote)
{
	char	*token_with_quotes_removed;
	int		token_len;
	int index;
	int j;

	index = 0;
	j = 0;
	token_len = ft_strlen(token);
	token_with_quotes_removed = __ft_calloc(sizeof(char) * (token_len + 1));
	while (token[index])
	{
		if (!is_in_lst_quote(index ,lst_quote))
		{
			token_with_quotes_removed[j] = token[index];
			j++;
		}
		index++;
	}
	return (token_with_quotes_removed);
}

char	*expand_token(char *token, t_lst_env *env_list)
{
	char	*var_content;
	char	*variable_name;
//	int var_len;
	int i;
	int quote_skiped;
	int var_content_len;
	int position_open_quote;
	int position_close_quote;
	t_lst_quote	*lst_quote;
	t_count_quote *nb_couple;

	nb_couple = count_quote_couple(token);
	lst_quote = NULL;
	quote_skiped = FALSE;
	var_content_len = 0;
	i = 0;
	while (token[i])
	{
		if (is_quote(token[i]))
		{
			position_open_quote = i;
			printf("position_open_quote = %d\n", position_open_quote);
			if (is_simple_quote(token[i]))
			{
				
				skip_quote(token, &i);
				if (token[i])
					printf("token[%d] after skip_quote = %c\n", i, token[i]);
				position_close_quote = i - 1;

				printf("position_close_quote = %d\n", position_close_quote);
				quote_skiped = TRUE;

				position_close_quote = i - 1;
			}
			else if (is_double_quote(token[i]))
			{
				i++;
				while (token[i] && !is_double_quote(token[i]))
				{
					if (is_dollar(token[i]))
					{
			//			var_len = get_var_length(token);
						variable_name = get_variable_to_expand_name(&token[i + 1]);
						printf("variable name: %s\n", variable_name);
						var_content = get_var_to_expand_content(variable_name, env_list);
						var_content_len = ft_strlen(var_content);
						if (!var_content)
						{
							printf("Variable doesn't exist\n");
							return (NULL);
						}
						insert_var_content_to_token(&token, var_content, i);
						i = i + (var_content_len-1);
						printf("token[%d] = %c\n", i, token[i]);
					}
					i++;
				}
				position_close_quote = i ;
						printf("position_close_quote = %d\n", position_close_quote);
			//	i++;
			}
				ft_lstquote_add_back(&lst_quote, create_quote_index(position_open_quote, position_close_quote));
			
		}
		printf("HERE token = [%s] && i = %d\n", token, i);
		if (is_dollar(token[i]))
		{
//			var_len = get_var_length(token);
			variable_name = get_variable_to_expand_name(&token[i + 1]);
			var_content = get_var_to_expand_content(variable_name, env_list);
			var_content_len = ft_strlen(var_content);
			if (!var_content)
			{
				printf("Variable doesn't exist\n");
				return (NULL);
			}
			insert_var_content_to_token(&token, var_content, i);
			i = i + (var_content_len - 1);
			printf("token[i] = %c\n", token[i]);
		}
		if (token[i] && !quote_skiped)
			i++;
		quote_skiped = FALSE;
	}
	print_lstquote(lst_quote);
	token = remove_quotes(token, lst_quote);
	printf("token = [%s]\n", token);
	return (token);
}
