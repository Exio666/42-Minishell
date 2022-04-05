/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:06:39 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/05 15:21:00 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
 *	primary_checker.c
 */

int		give_next_character(char *str, int start, char c);
int		check_error(t_checker *check, char *str);
void	init_struct_checker(t_checker *check);
int		primary_checker(char *commande);



/*
 *	and_or_checker.c
 */

void	and_checker(char *commande, t_checker *check);
void	or_checker(char *commande, t_checker *check);
int		and_or_pipe_checker(char *commande, t_checker *check);

/*
 *	quote_checker.c
 */

int		quote_parenthise_checker(char *commande, t_checker *check);
int		quote_jump(char *commande, t_checker *check);

#endif 