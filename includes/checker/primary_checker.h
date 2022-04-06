/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:06:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/06 14:09:58 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMARY_CHECKER_H
# define PRIMARY_CHECKER_H

#include "minishell.h"

int		give_next_character(char *str, int start, char c);
int		check_error(t_checker *check, char *str);
void	init_struct_checker(t_checker *check);
int		primary_checker(char *commande);

#endif