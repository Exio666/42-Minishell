/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:39:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 16:27:25 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dollar(char c)
{
	if (c == '$')
		return (TRUE);
	return (FALSE);
}

int	get_var_length(char	*command)
{
	int length;

	length = 0;
	while (command[length] != '\0' && !is_space(command[length]))
		length++;
	return (length);
}

char	*get_variable_to_expand_name(char *command)
{
	int var_len;
	char *var_name;
	int i;

	i = 0;
	var_len = get_var_length(command);
	if (var_len == 0)
		return (NULL);
	var_name = __ft_calloc(sizeof(char) * (var_len + 1));
	ft_strlcpy (var_name, command, var_len + 1);
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
	
void	insert_var_content_to_command(char **command, char *var_content, int start_index)
{
	int command_len;
	int var_content_len;
	int expanded_command_len;
	int var_len;
	char	*expanded_command;
	int i = 0;

//	printf("0 command:[%s]\n", *command);
	
	command_len = ft_strlen(*command);
	var_content_len = ft_strlen(var_content);
	expanded_command = __ft_calloc(sizeof(char) * (command_len + var_content_len + 1));
	
	ft_strlcpy(expanded_command, *command, start_index + 1);
//	printf("1 expanded_command: [%s]\n", expanded_command);
	
	ft_strlcat(expanded_command, var_content, (command_len + var_content_len + 1));
//	printf("2 expanded_command: [%s]\n", expanded_command);
	
	
	expanded_command_len = ft_strlen(expanded_command);
	var_len = get_var_length(&(*command)[start_index + 1]);
	command_len = ft_strlen(&(*command)[start_index + var_len]);
	
	ft_strlcat(expanded_command, &(*command)[start_index + var_len + 1], (expanded_command_len + command_len + 1));
//	printf("3 expanded_command: [%s]\n", expanded_command);
	
//	free(*command);
	*command = expanded_command;
}

char	*expand_command(char *command, t_lst_env *env_list)
{
	char	*var_content;
	char	*variable_name;
	int var_len;
	int i;
printf("%s\n", command);
	i = 0;
	while (command[i])
	{
		
		if (is_dollar(command[i]))
		{

			var_len = get_var_length(command);
			variable_name = get_variable_to_expand_name(&command[i + 1]);
//			if (variable_name)
//				printf("%s\n", variable_name);	

			var_content = get_var_to_expand_content(variable_name, env_list);
//			printf("var_content: [%s]\n", var_content);
			if (!var_content)
			{
				printf("Variable doesn't exist\n");
				return (NULL);
			}
			insert_var_content_to_command(&command, var_content, i);
//			printf("command : %s\n", command);
		}
		i++;
	}
	return (command);
}
