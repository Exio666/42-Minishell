/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tab_to_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:16:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 17:06:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TAB_TO_LIST_H
# define ENV_TAB_TO_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include "minishell.h"

typedef struct s_lst_env
{
	char				*name;
	char				*content;
	struct s_lst_env	*next;
	struct s_lst_env	*prev;
}	t_lst_env;

t_lst_env	*transform_env_array_in_list(char **envp_array);
t_lst_env	*create_list_env_elem(char *variable_env);
char		*get_variable_name(char	*variable_env);
char		*get_variable_content(char	*variable_env);
int			get_start_content_index(char	*variable_env);
int			get_var_name_len(char	*variable_env);

int			get_var_content_len(char	*variable_env);

t_lst_env	*ft_dlist_env_last(t_lst_env *lst);
void		ft_dlist_env_add_back(t_lst_env **alst, t_lst_env *new);

void		print_lst_env(t_lst_env	*list_elem);

#endif