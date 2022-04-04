/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:24:05 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/01 15:17:333 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int main(int argc, char **argv)
{
	t_logical_op	**logical_op;
	
	attribute_level(argv[1]);
	logical_op = create_logical_op_array(argv[1]);
	return 0;
}



t_logical_op	**malloc_logical_op_reference(char *user_input)
{
	t_logical_op	**logical_op;
	int					size;
	int				i;

	i = 0;
	if (user_input == NULL)
		return (NULL);
	size = count_logical_op(user_input);
	logical_op = calloc(size + 1, sizeof(t_logical_op*)); // WARNING CALLOC!!!!
	if (logical_op == NULL)
		return (NULL);
	while (i < size)
	{
		logical_op[i] = calloc(1, sizeof(t_logical_op));
		if (logical_op[i] == NULL)
			return (NULL);
		i++;
	}
	return (logical_op);
}

t_logical_op	**create_logical_op_array(char *user_input)
{
	t_logical_op	**logical_op;
	int				actual_log_op;
	int				i;
	int				j;

	logical_op = malloc_logical_op_reference(user_input);
	if (logical_op == NULL)
		printf("FAIL 0\n");
	i = 0;
	j = 0;
	while (user_input[i] && user_input[i + 1])
	{
		if (user_input[i] && user_input[i + 1] && is_logical_operator_char(user_input[i]) == TRUE)
		{
			actual_log_op = get_logical_op_from_begin(user_input, i);
			if (actual_log_op != OPERATOR_NOT_FOUND)
			{
				update_logical_op(logical_op[j], i, actual_log_op);
				j++;
			}
			i++;
		}
		i++;
	}
	return (logical_op);
}

void	update_logical_op(t_logical_op *logical_op, int position, int actual_log_op)
{	
	logical_op->begin_position = position;
	logical_op->type = actual_log_op;
	if (actual_log_op == AND_OPERATOR)
	{
		logical_op->symbol[0] = '&';
		logical_op->symbol[1] = '&';
	}
	else if (actual_log_op == OR_OPERATOR)
	{
		logical_op->symbol[0] = '|';
		logical_op->symbol[1] = '|';
	}
}

int	count_logical_op(char *user_input)
{	
	int	actual_logical_op;
	int	logical_op_count;
	int	i;

	if (user_input == NULL)
		return (-1);
	i = 0;
	logical_op_count = 0;
	while (user_input[i + 1])
	{
		if (user_input[i + 1] && is_logical_operator_char(user_input[i]) == TRUE)
		{
			actual_logical_op = get_logical_op_from_begin(user_input, i);
			if (actual_logical_op != OPERATOR_NOT_FOUND)
				logical_op_count++;
			i++;
		}
		i++;
	}
	return (logical_op_count);
}

void parser(char *user_input)
{
	t_logical_op	**logical_op;
	int len;
	int i;
	
	len = strlen(user_input);
	i = len - 1;
	while (i >= 0)
	{
		if ((i - 1 >= 0) && (is_logical_operator_char(user_input[i]) == TRUE))
		{
			if (get_logical_op_from_end(user_input, i) != OPERATOR_NOT_FOUND)
			{
				printf("Logical operator found\n");
			}
			i--;
		}
		i--;
	}
}

/*
On parcout la chaine depuis le début pour creer un tableau de struct contenant les && et les ||
*/

int	is_logical_operator_char(char c)
{
	if (c == '&' || c == '|')
		return (TRUE);
	else
		return (FALSE);
}

int	is_and_symbol(char c)
{
	if (c == '&')
		return (TRUE);
	else
		return (FALSE);
}
int	is_or_symbol(char c)
{
	if (c == '|')
		return (TRUE);
	else
		return (FALSE);	
}

int	get_logical_op_from_end(char *user_input, int i)
{
	if (is_and_symbol(user_input[i]) && is_and_symbol(user_input[i - 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i]) && is_or_symbol(user_input[i - 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}

int	get_logical_op_from_begin(char *user_input, int i)
{
	if (is_and_symbol(user_input[i]) && is_and_symbol(user_input[i + 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i]) && is_or_symbol(user_input[i + 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}

//un tableau à deux dimensions avec l''user input et pour chaque caractère un niveau d'execution
// en suite on parcourt tous ces niveaux d'executiion en partant de la fin

t_input_level *malloc_input_level(char *user_input)
{
	int	len;
	t_input_level *input_level;

	len = strlen(user_input);
	input_level = calloc(1, sizeof(t_input_level));
	input_level->level = calloc(len, sizeof(int));
	return(input_level);
}

int	is_open_parenthesis(char c)
{
	if (c == '(')
		return (TRUE);
	else
		return (FALSE);
}

int	is_close_parenthesis(char c)
{
	if (c == ')')
		return (TRUE);
	else
		return (FALSE);
}

void	attribute_level(char *user_input)
{
	int				level;
	int				i;
	t_input_level	*input_level;

	int	len;
	len = strlen(user_input);
	input_level = malloc_input_level(user_input);
	input_level->input = strdup(user_input);
	i = 0;
	level = 0;
	while (input_level->input[i])
	{
		input_level->level[i] = level;
		if (is_open_parenthesis(input_level->input[i]))
		{
			level++;
		}
		else if (is_close_parenthesis(input_level->input[i]))
		{
			level--;
		}
	
		i++;
	}
	printab_input_level(input_level, len);
}

void printab_input_level(t_input_level	*input_level, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%c ", input_level->input[i]);
	}
	printf("\n");
	for (int j = 0; j < len; j++)
	{
		printf("%d ", input_level->level[j]);
	}
	printf("\n");
}