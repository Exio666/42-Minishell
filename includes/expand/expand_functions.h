/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:10:55 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 10:41:55 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_FUNCTIONS_H
# define EXPAND_FUNCTIONS_H

# include "minishell.h"

void	expand_command(t_lst_token *token, t_lst_env *env_list);
char	*expand_variable(char *token, int *index, t_lst_env *env_list);
int		expand_in_quotes(char **token, int *i, t_lst_env *env_list);
t_lst_token	*expand_token(t_lst_token *token, t_lst_env *env_list);

#endif