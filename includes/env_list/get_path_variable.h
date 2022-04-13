/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_variable.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:00:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 10:51:03 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PATH_VARIABLE_H
# define GET_PATH_VARIABLE_H

# include "minishell.h"

char	**split_path_env_variable(char *path_env_variable);
char	*get_path_env_variable(t_lst_env	*list_env_var);
void	free_char_two_dim_array(char **array);
void	print_char_two_dim_array(char **array);

#endif