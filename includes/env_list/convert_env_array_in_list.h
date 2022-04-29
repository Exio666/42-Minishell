/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_array_in_list.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:42 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 12:44:49 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_ENV_ARRAY_IN_LIST_H
# define CONVERT_ENV_ARRAY_IN_LIST_H

# include "minishell.h"

t_lst_env	*convert_env_array_in_list(char **envp_array);

#endif