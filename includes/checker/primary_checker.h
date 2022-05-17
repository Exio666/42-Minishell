/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:06:40 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 08:50:30 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMARY_CHECKER_H
# define PRIMARY_CHECKER_H

# include "minishell.h"

int		check_command_is_ok(char *command_line);
int		give_next_character(char *str, int start, char c);
int		check_error(t_checker *check, char *str);
void	init_struct_checker(t_checker *check);
int		primary_checker(char *commande);

#endif