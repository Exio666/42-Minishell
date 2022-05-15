/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:15:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:46:04 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_variable_name(char	*variable_env)
{
	int		variable_name_len;
	char	*variable_name;

	variable_name_len = get_var_name_len(variable_env);
	variable_name = __ft_calloc_env(sizeof(char) * (variable_name_len + 1));
	ft_strlcpy(variable_name, variable_env, variable_name_len + 1);
	return (variable_name);
}

char	*get_variable_content(char	*variable_env)
{
	char	*variable_content;
	int		len;
	int		start_content_index;

	if (!variable_env)
		return (NULL);
	start_content_index = get_start_content_index(variable_env);
	len = get_var_content_len(variable_env);
	variable_content = __ft_calloc_env(sizeof(char) * (len + 1));
	ft_strlcpy(variable_content, &variable_env[start_content_index], len + 1);
	return (variable_content);
}

int	get_var_name_len(char	*variable_env)
{
	int	len;

	len = 0;
	while (variable_env[len] && variable_env[len] != '=')
		len++;
	return (len);
}

int	get_start_content_index(char	*variable_env)
{
	int	index;

	index = 0;
	while (variable_env[index] && variable_env[index] != '=')
		index++;
	if (variable_env[index] == '=')
		index++;
	return (index);
}

int	get_var_content_len(char	*variable_env)
{
	int	len;
	int	start_content_index;

	start_content_index = get_start_content_index(variable_env);
	len = 0;
	while (variable_env[start_content_index + len])
		len++;
	return (len);
}
