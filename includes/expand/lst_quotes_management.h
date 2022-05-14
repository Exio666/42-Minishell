/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_quotes_management.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:09:59 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 21:29:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_QUOTES_MANAGEMENT_H
# define LST_QUOTES_MANAGEMENT_H

# include "minishell.h"

t_lst_quote	*create_quote_index(int open_quote_index, int close_quote_index);
t_lst_quote	*ft_lstquote_last(t_lst_quote *lst);
void		ft_lstquote_add_back(t_lst_quote **alst, t_lst_quote *new);
int			is_in_lst_quote(int index, t_lst_quote *lst_quote);
void		print_lstquote(t_lst_quote *lst_quote);

#endif
