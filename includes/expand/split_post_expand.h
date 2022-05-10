/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_post_expand.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:56:42 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 12:59:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_POST_EXPAND_H
# define SPLIT_POST_EXPAND_H

# include "minishell.h"

char	**split_post_expand(t_lst_token *token);

#endif