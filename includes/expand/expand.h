/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:23:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 12:24:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAN_H

# include "minishell.h"


int	is_dollar(char c);
int	get_var_length(char	*command);
char	*get_variable_to_expand_name(char *command);
char *get_var_to_expand_content(char *var_name, t_lst_env *env_list);
void	insert_var_content_to_command(char **command, char *var_content, int start_index);
char	*expand_command(char *command, t_lst_env *env_list);

#endif
