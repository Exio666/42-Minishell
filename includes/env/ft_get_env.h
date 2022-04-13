/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:58:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/13 11:59:40 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_ENV_H
# define FT_GET_ENV_H

#include "minishell.h"

char *join_env_var(t_lst_env *lst);
char *ft_get_env(t_lst_env **env_list, char *name);

#endif