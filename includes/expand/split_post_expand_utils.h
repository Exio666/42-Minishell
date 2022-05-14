/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:37:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 21:30:02 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_POST_EXPAND_UTILS_H
# define SPLIT_POST_EXPAND_UTILS_H

# include "minishell.h"

int		space_is_separator(t_lst_token *token, int index);
void	skip_space_out_of_quotes(t_lst_token *token, int *index);

#endif