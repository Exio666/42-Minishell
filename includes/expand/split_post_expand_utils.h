/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:37:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:30:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_POST_EXPAND_UTILS_H
# define SPLIT_POST_EXPAND_UTILS_H

# include "minishell.h"

int		space_is_separator(t_lst_token *token, int index);
void	skip_space_out_of_quotes(t_lst_token *token, int *index);

#endif