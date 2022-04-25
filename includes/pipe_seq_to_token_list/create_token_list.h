/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:38:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:40:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_TOKEN_LIST_H
# define CREATE_TOKEN_LIST_H

#include "minishell.h"

t_token	*create_token(char	*space_split);
t_list	*create_token_list(char **split);
int		find_token_type(char *str);
void	add_token_to_lst(t_list **lst, t_token *token);
char	*dup_without_extra_space(char *str);

#endif