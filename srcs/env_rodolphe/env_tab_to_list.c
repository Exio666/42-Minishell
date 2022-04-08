/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tab_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:15:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/08 17:22:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_tab_to_list.h"

int	main(int argc, char **argv, char **envp)
{
	(void)(argc);
	(void)(argv);
	transform_env_array_in_list(envp);
	return (0);
}

t_lst_env	*transform_env_array_in_list(char **envp_array)
{
	t_lst_env	*head_list;
	t_lst_env	*list_elem;
	int			i;
	
	head_list = NULL;
	i = 0;
	while (envp_array[i])
	{
		printf("TEMOIN 0\n");
		list_elem = create_list_env_elem(envp_array[i]);
		printf("TEMOIN 1\n");
		ft_dlist_env_add_back(&head_list, list_elem);
		printf("TEMOIN 2\n");
		i++;
	}
	return (head_list);
}


t_lst_env	*create_list_env_elem(char *variable_env)
{
	t_lst_env	*list_elem;
	printf("TEMOIN A\n");
	list_elem = __ft_calloc(sizeof(t_lst_env));
	printf("TEMOIN B\n");
	list_elem->name = get_variable_name(variable_env);
	printf("TEMOIN C\n");
	list_elem->content = get_variable_content(variable_env);
	printf("TEMOIN D\n");
	list_elem->next = NULL;
	list_elem->prev = NULL;
	return (list_elem);
}

char	*get_variable_name(char	*variable_env)
{
	int		variable_name_len;
	char	*variable_name;

	printf("TEMOIN B1\n");
	variable_name_len = get_var_name_len(variable_env);
	printf("TEMOIN B2\n");
	variable_name = __ft_calloc(sizeof(char) * (variable_name_len + 1));
	printf("TEMOIN B3\n");
	ft_strlcpy(variable_name, variable_env, variable_name_len + 1);
	printf("TEMOIN B4\n");
	return (variable_env);
}

char	*get_variable_content(char	*variable_env)
{
	char	*variable_content;
	int		len;
	int		start_content_index;

	start_content_index = get_start_content_index(variable_env);
	len = get_var_content_len(variable_env);
	variable_content = __ft_calloc(sizeof(char) * (len + 1));
	ft_strlcpy(variable_content, &variable_env[start_content_index], len + 1);
	return (variable_env);
}

void	ft_dlist_env_add_back(t_lst_env **alst, t_lst_env *new)
{
	t_lst_env	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_dlist_env_last(*alst);
	tmp->next = new;
	new->prev = tmp;
}


int get_var_name_len(char	*variable_env)
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

int get_var_content_len(char	*variable_env)
{
	int	len;
	int	start_content_index;
	
	start_content_index = get_start_content_index(variable_env);
	len = 0;
	while (variable_env[start_content_index + len])
		len++;
	return (len);		
}

t_lst_env	*ft_dlist_env_last(t_lst_env	*lst)
{
	t_lst_env	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}
