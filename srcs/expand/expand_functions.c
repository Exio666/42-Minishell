/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:39:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/12 15:30:16 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_token *skip_new_token(t_lst_token *token, t_split *split)
{
	int	i;

	i = 0;
	while (token && i < (split->size_2d_array - 1))
	{
		token = token->next;	
		i++;
	}
	return (token);
}

void	expand_command(t_lst_token *token, t_lst_env *env_list)
{
	t_split	*split;

	split = NULL;
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (token && token->type == TOK_WORD)
		{
			token = expand_token(token, env_list);
			split = split_post_expand(token);
			insert_split_in_token_list(token, split);
			token = skip_new_token(token, split);
		}
		if (token)
			token = token->next;
	}
}

char	*expand_variable(char *token, int *index, t_lst_env *env_list)
{
	char	*var_content;
	char	*variable_name;
	int		var_content_len;

	var_content = NULL;
	variable_name = NULL;
	var_content_len = 0;
	variable_name = get_variable_to_expand_name(&token[*index + 1]);
	var_content = get_var_to_expand_content(variable_name, env_list);
	if (!var_content)
	{
		var_content = __ft_calloc(sizeof(char) * 1);
		var_content_len = 0;
	}
	else
		var_content_len = ft_strlen(var_content);
	insert_var_content_to_token(&token, var_content, *index);
	*index = *index + (var_content_len - 1);
	return (token);
}

int	expand_in_quotes(char **token, int *i, t_lst_env *env_list)
{
	int	closing_quote_position;

	if (is_simple_quote((*token)[*i]))
	{
		closing_quote_position = skip_quote(*token, i);
		closing_quote_position--;
	}
	else
	{
		*i = *i + 1;
		while ((*token)[*i] && !is_double_quote((*token)[*i]))
		{
			if (is_dollar((*token)[*i]))
				*token = expand_variable(*token, i, env_list);
			*i = *i + 1;
		}
		closing_quote_position = *i;
	}
	return (closing_quote_position);
}

int	is_wildcard(char c)
{
	if (c == '*')
		return (TRUE);
	else
		return (FALSE);
}
/*
char	*expand_wildcard(char **token, int *i, t_lst_env *env_list)
{
	char	*wildcard_content;
	int		wildcard_content_len;

	wildcard_content = NULL;
	wildcard_content_len = 0;
	wildcard_content = get_wildcard_content();
	if (!wildcard_content)
	{
		wildcard_content = __ft_calloc(sizeof(char) * 1);
		wildcard_content_len = 0;
	}
	else
		wildcard_content_len = ft_strlen(wildcard_content);
	insert_var_content_to_token(&token, wildcard_content, *index);
	*index = *index + (wildcard_content_len - 1);
	return (token);
}
*/
/* il n'y  a pas d'expand de wildcard entre quote, mais il falloir mettre a jour la position des quotes à remove, car l'expansion 
de la wildcard pourrait les déplacés. (position quote = position quote + wildcard expanded len?)
*/
/*
t_lst_token	*expand_all_wildcards(t_lst_token *token, t_lst_env *env_list)
{
	int				i;

	i = 0;
	while (token && token->str[i])
	{
		if (is_wildcard(token->str[i]) && !token->in_quotes[i])
			expand_ex
		i++;
	}
	return (token);
}
*/
t_lst_token	*expand_all_variables(t_lst_token *token, t_lst_env *env_list)
{
	int				i;
	t_quote_index	quote;
	t_lst_quote		*elem;

	i = 0;
	while (i != -1 && token && token->str[i])
	{
		quote.open = -1;
		if (token->str[i] && is_quote(token->str[i]))
		{
			quote.open = i;
			quote.close = expand_in_quotes(&token->str, &i, env_list);
			elem = create_quote_index(quote.open, quote.close);
			ft_lstquote_add_back(&token->lst_quote, elem);
		}
		if (token->str[i] && is_dollar(token->str[i]))
			token->str = expand_variable(token->str, &i, env_list);
		if (i != -1 && token && token->str && token->str[i])
			move_foward_expanding_var(quote.open, token->str, &i);
	}
	return (token);
}

void print_token_str_with_active_char(t_lst_token *token)
{
	for (int i= 0; token->str[i]; i++)
		printf("%c", token->str[i]);
	printf("\n");
	for (int i= 0; token->str[i]; i++)
		printf("%d", token->in_quotes[i]);
	printf("\n");
}

t_lst_token	*expand_token(t_lst_token *token, t_lst_env *env_list)
{

	if (ft_strlen(token->str) == 0)
		return (token);
	token = expand_all_variables(token, env_list);
	token->str = remove_quotes(token, token->lst_quote);
//	print_token_str_with_active_char(token);
//	token = expand_all_wildcards(token, env_list);
	return (token);
}
/*
void	move_foward_expanding_wildcard(int open_quote, char *token_str, int *index)
{
	
}
*/
void	move_foward_expanding_var(int open_quote, char *token_str, int *index)
{
	if (open_quote != -1)
	{
		if (!is_simple_quote(token_str[open_quote]))
			(*index)++;
	}
	else
		(*index)++;
}
