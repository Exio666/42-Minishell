/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:15:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:26:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	expand_wildcard_command(t_lst_token *token)
{
	t_lst_token	*new_token_list;
	int			size_new_token_list;

	new_token_list = NULL;
	size_new_token_list = 0;
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (is_an_asterix_out_of_quotes(token))
		{
			new_token_list = expand_wildcard_token(token);
			if (new_token_list)
			{
				size_new_token_list = ft_size_token_list(new_token_list);
				insert_new_token_list(new_token_list, token);
				token = move_to_last_new_token(token, size_new_token_list);
				new_token_list = NULL;
			}
		}
		if (token)
			token = token->next;
	}
}

void	insert_new_token_list(t_lst_token *new_token_list,
	t_lst_token *current_token)
{
	t_lst_token	*tmp;

	current_token->str = new_token_list->str;
	current_token->in_quotes = new_token_list->in_quotes;
	tmp = current_token->next;
	current_token->next = new_token_list->next;
	while (current_token->next)
		current_token = current_token->next;
	current_token->next = tmp;
}

int	ft_size_token_list(t_lst_token *token)
{
	int	count;

	count = 0;
	if (!token)
		return (count);
	while (token)
	{
		count++;
		token = token->next;
	}
	return (count);
}

int both_start_with_dot(char *pattern, char *str)
{
	if (is_dot(str[0]) && is_dot(pattern[0]))
		return (TRUE);
	else
		return (FALSE);
}

t_lst_token	*expand_wildcard_token(t_lst_token *token)
{
	t_lst_token		*token_list;
	t_lst_token		*new_token;
	struct dirent	*entity;
	DIR				*dir;

	token_list = NULL;
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		new_token = NULL;
		if (!is_dot(entity->d_name[0])
			|| both_start_with_dot(entity->d_name, token->str))
		{
			if (str_is_matching_pattern(token->str, entity->d_name))
				new_token = create_token(entity->d_name);
			if (new_token)
				ft_lstadd_back_token(&token_list, new_token);
		}
		entity = readdir(dir);
	}
	return (token_list);
}
