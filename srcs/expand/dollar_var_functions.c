/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_var_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:02:54 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 19:07:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var_length(char	*token)
{
	int	length;

	length = 0;
	while (token[length] != '\0' && !is_white_space(token[length])
		&& !is_quote(token[length]) && !is_dollar(token[length])
		&& !is_wildcard(token[length]))
		length++;
	return (length);
}

char	*get_variable_to_expand_name(char *token)
{
	int		var_len;
	char	*var_name;

	var_len = get_var_length(token);
	if (var_len == 0)
		return (NULL);
	var_name = __ft_calloc(sizeof(char) * (var_len + 1));
	ft_strlcpy (var_name, token, var_len + 1);
	return (var_name);
}

static int	ft_strcmp(char *s1, char *s2)
{		
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
char	*get_var_to_expand_content(char *var_name, t_lst_env *env_list)
{
	if (ft_strcmp(var_name, "?") == 0)
		return (ft_itoa(g_exit_status));
	while (env_list)
	{
		if (ft_strcmp(var_name, env_list->name) == 0)
			return (env_list->content);
		env_list = env_list->next;
	}
	return (NULL);
}

void	insert_var_content_to_token(char **token, char *var_content,
			int start_index)
{
	int		token_len;
	int		var_content_len;
	int		expanded_token_len;
	int		var_len;
	char	*expanded_token;

	token_len = ft_strlen(*token);
	var_content_len = ft_strlen(var_content);
	expanded_token = __ft_calloc(sizeof(char) * (token_len
				+ var_content_len + 1));
	ft_strlcpy(expanded_token, *token, start_index + 1);
	ft_strlcat(expanded_token, var_content, (token_len + var_content_len + 1));
	expanded_token_len = ft_strlen(expanded_token);
	var_len = get_var_length(&(*token)[start_index + 1]);
	token_len = ft_strlen(&(*token)[start_index + var_len]);
	ft_strlcat(expanded_token, &(*token)[start_index + var_len + 1],
		(expanded_token_len + token_len + 1));
	*token = expanded_token;
}
