/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:39:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 08:58:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** PROBLEM avec
export a=bon
echo' $a'
*/


//si je recuperer la position des quotes, je peux eviter de split qvec les espaces qui se trouvaient a l interieur de ces quotes

void	expand_command(t_lst_token *token, t_lst_env *env_list)
{
	char	**split;
	int		size;
	int		i;

	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (!token)
			break ;
		if (token->type == TOK_WORD)
		{
			if (token->str)
				token->str = expand_token(token->str, env_list);
			if (token->type == TOK_WORD)										// START ADD
			{
				split = split_pipe_by_space(token->str);
				size = size_2d_array(split);
				if (size > 1)
					insert_split_in_token_list(token, split);
				i = 0;
				while (token && i < size - 1)
				{
					i++;
					token = token->next;
				}
			}																	//END ADD
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
	var_content_len = ft_strlen(var_content);
	if (!var_content)
	{
		printf("Variable doesn't exist\n");
		return (NULL);
	}
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
	else if (is_double_quote((*token)[*i]))
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


char	*expand_token(char *token, t_lst_env *env_list)
{
	int				i;
	t_quote_index	quote;
	t_lst_quote		*lst_quote;
	t_lst_quote		*elem;

	lst_quote = NULL;
	i = 0;
	while (token[i])
	{
		quote.open = i;
		if (is_quote(token[i]))
		{
			quote.close = expand_in_quotes(&token, &i, env_list);
			elem = create_quote_index(quote.open, quote.close);
			ft_lstquote_add_back(&lst_quote, elem);
		}
		if (is_dollar(token[i]))
			token = expand_variable(token, &i, env_list);
		if (token[i] && !is_simple_quote(token[quote.open]))
			i++;
	}
	token = remove_quotes(token, lst_quote);
	return (token);
}
