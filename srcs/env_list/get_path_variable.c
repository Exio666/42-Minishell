/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:18:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 11:13:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_path_env_variable(char *path_env_variable)
{
	char	*current_path;
	char	**all_path;
	int		i;
	int		path_len;

	all_path = ft_split(ft_strchr(path_env_variable, '=') + 1, ':');
	i = 0;
	while (all_path[i] != NULL && all_path[i][0] != 0)
	{
		path_len = ft_strlen(all_path[i]);
		current_path = __ft_calloc(sizeof(*current_path) * (path_len + 1));
		if (!current_path)
			__ft_calloc(-1);
		ft_strlcpy(current_path, all_path[i], path_len + 1);
		current_path[path_len] = '\0';
		all_path[i] = current_path;
		i++;
	}
	return (all_path);
}

char	*get_path_env_variable_from_lst(t_lst_env	*list_env_var)
{
	while (list_env_var)
	{
		if (ft_strncmp(list_env_var->name, "PATH=", 5) == 0)
			return (list_env_var->content);
		list_env_var = list_env_var->next;
	}
	return (NULL);
}

void	free_char_two_dim_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	print_char_two_dim_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
