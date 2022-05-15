/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_var_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:12:34 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:26:05 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOLLAR_VAR_FUNCTIONS_H
# define DOLLAR_VAR_FUNCTIONS_H

# include "minishell.h"

int		get_var_length(char	*token);
char	*get_variable_to_expand_name(char *token);
char	*get_var_to_expand_content(char *var_name, t_lst_env *env_list);
void	insert_var_content_to_token(char **token, char *var_content,
			int start_index);

#endif