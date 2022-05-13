/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:24:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/13 15:25:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_UTILS_H
# define EXPAND_UTILS_H

# include "minishell.h"

t_lst_token *skip_new_token(t_lst_token *token, t_split *split);
void print_token_str_with_active_char(t_lst_token *token);
void	move_foward_expanding_var(int open_quote, char *token_str, int *index);

#endif