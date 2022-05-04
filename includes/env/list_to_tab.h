/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:25:36 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 14:30:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_TO_TAB_H
# define LIST_TO_TAB_H

# include "minishell.h"

int		env_lst_size(t_lst_env *list);
char	**env_list_to_tab(t_lst_env **list_env);

#endif