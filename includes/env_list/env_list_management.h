/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_management.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:56:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 10:50:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_MANAGEMENT_H
# define ENV_LIST_MANAGEMENT_H

# include "minishell.h"

t_lst_env	*create_list_env_elem(char *variable_env);
void		ft_dlist_env_add_back(t_lst_env **alst, t_lst_env *new);
t_lst_env	*ft_dlist_env_last(t_lst_env	*lst);
void		print_lst_env(t_lst_env	*list_elem);
void		free_t_lst_env(t_lst_env	*list_elem);

#endif