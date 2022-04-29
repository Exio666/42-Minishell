/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:38:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 16:16:46 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_TOKEN_LIST_H
# define CREATE_TOKEN_LIST_H

#include "minishell.h"

t_lst_token	*create_token_list(char **split);
t_lst_token	*create_token(char	*space_split);
t_lst_token	*ft_lstlast_token(t_lst_token *token);
void		ft_lstadd_back_token(t_lst_token **alst, t_lst_token *new);
int			find_token_type(char *str);
char		*dup_without_extra_space(char *str);

#endif