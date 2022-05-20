/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:10:55 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/20 23:43:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_FUNCTIONS_H
# define EXPAND_FUNCTIONS_H

# include "minishell.h"

t_lst_token	*expand_all_variables(t_lst_token *token, t_lst_env *env_list);
void		move_foward_expanding_var(int open_quote,
				char *token_str, int *index);
void		expand_command(t_lst_token *token, t_lst_env *env_list);
char		*expand_variable(char *token, int *index, t_lst_env *env_list);
int			expand_in_quotes(char **token, int *i, t_lst_env *env_list);
t_lst_token	*expand_token(t_lst_token *token, t_lst_env *env_list);

#endif