/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:13:17 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 14:15:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_TOKEN_H
# define CREATE_TOKEN_H

# include "minishell.h"

t_lst_token	*create_token(char	*space_split);
t_lst_token	*create_token_for_split(char	*space_split, int *in_quotes);
t_lst_token	*create_token_expand(char	*space_split);

int			find_token_type(char *str);
char		*dup_without_extra_space(char *str);

#endif