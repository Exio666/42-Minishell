/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:34 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 10:49:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_MANAGEMENT_H
# define LIST_MANAGEMENT_H

# include "minishell.h"

/*----- list_management.c -----*/
/*
t_list	*lstnew(void *elem);
t_list	*lstlast(t_list *lst);
void	lstadd_back(t_list **alst, t_list *new);
*/
void	ft_lstdelone_parser(t_list **lst);

#endif