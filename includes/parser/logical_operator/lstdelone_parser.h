/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:25:18 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 16:25:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTDELONE_PARSER_H
# define LSTDELONE_PARSER_H

# include "minishell.h"

/*----- list_management.c -----*/
/*
t_list	*lstnew(void *elem);
t_list	*lstlast(t_list *lst);
void	lstadd_back(t_list **alst, t_list *new);
*/
void	ft_lstdelone_parser(t_list **lst);

#endif