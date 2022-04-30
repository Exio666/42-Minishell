/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:12:25 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/30 17:13:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TO_TAB_H
# define LIST_TO_TAB_H

#include "minishell.h"

int env_lst_size(t_lst_env *list);
char	**env_list_to_tab(t_lst_env **list_env);

#endif