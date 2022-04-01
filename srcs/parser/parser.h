/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/01 16:05:19 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>


# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define FALSE 0
# define TRUE 1


void parser(char *user_input);
int	is_logical_operator_char(char c);
int	is_and_symbol(char c);
int	is_or_symbol(char c);
int	get_logical_operator(char *user_input, int i);

#endif