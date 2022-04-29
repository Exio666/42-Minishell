/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:39:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 18:38:06 by rpottier         ###   ########.fr       */
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

	length = 0;
	while (token[length] != '\0' && !is_space(token[length]))
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
	int i = 0;

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

char	*expand_token(char *token, t_lst_env *env_list)
{
	char	*var_content;
	char	*variable_name;
	int var_len;
	int i;

	i = 0;
	while (token[i])
	{
		if (is_dollar(token[i]))
		{

			var_len = get_var_length(token);
			variable_name = get_variable_to_expand_name(&token[i + 1]);
			var_content = get_var_to_expand_content(variable_name, env_list);
			if (!var_content)
			{
				printf("Variable doesn't exist\n");
				return (NULL);
			}
			insert_var_content_to_token(&token, var_content, i);
		}
		i++;
	}
	return (token);
}
