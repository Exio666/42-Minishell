/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_token_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:19:30 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 20:19:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_TOKEN_LIST_H
# define SORT_TOKEN_LIST_H

# include "minishell.h"

int		size_token_list(t_lst_token *token_list);
void	sort_array(t_lst_token **array, int size);
void	sort_token_list(t_lst_token **token_list);

#endif