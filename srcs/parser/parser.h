/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/03 22:12:32 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_logical_op
{
	char			symbol[3];
	unsigned int	type;
	unsigned int	begin_position;
}	t_logical_op;

typedef enum e_type_token
{
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
	PIPE_SEQUENCE,
	OR,
	AND
}	t_type_token;

# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define FALSE 0
# define TRUE 1

t_logical_op	**malloc_logical_op_reference(char *user_input);
t_logical_op	**create_logical_op_array(char *user_input);
void	update_logical_op(t_logical_op *logical_op, int position, int actual_log_op);
int	count_logical_op(char *user_input);
void parser(char *user_input);
int	is_logical_operator_char(char c);
int	is_and_symbol(char c);
int	is_or_symbol(char c);
int	get_logical_op_from_end(char *user_input, int i);
int	get_logical_op_from_begin(char *user_input, int i);


typedef struct s_input_level
{
	char	*input;
	int		*level;
}	t_input_level;

t_input_level *malloc_input_level(char *user_input);
int	is_open_parenthesis(char c);
int	is_close_parenthesis(char c);
void	attribute_level(char *user_input);
void printab_input_level(t_input_level	*input_level, int len);

#endif