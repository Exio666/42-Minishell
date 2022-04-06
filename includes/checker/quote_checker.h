/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:07:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/06 15:28:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_CHECKER_H
# define QUOTE_CHECKER_H

# include "minishell.h"

int		give_next_character(char *str, int start, char c);
int		check_error(t_checker *check, char *str);
void	init_struct_checker(t_checker *check);
int		primary_checker(char *commande);

#endif