/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:19:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 14:46:29 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include "minishell.h"

int			is_redirect_token(t_type_token token_type);
int			is_str_token(t_type_token token_type);
int			is_heredoc_token(t_type_token token_type);
int			count_tok_word(t_lst_token *token);
t_lst_token	*skip_two_token(t_lst_token *token);

#endif
