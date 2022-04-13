/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:15:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 10:51:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FUNCTIONS_H
# define GET_FUNCTIONS_H

# include "minishell.h"

char	*get_variable_name(char	*variable_env);
char	*get_variable_content(char	*variable_env);
int		get_var_name_len(char	*variable_env);
int		get_start_content_index(char	*variable_env);
int		get_var_content_len(char	*variable_env);

#endif