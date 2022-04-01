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

int main(int argc, const char * argv[])
{
	char *user_input;

	user_input = readline("Enter your string : ");
	parser(user_input);
	return 0;
}

void parser(char *user_input)
{
	int len;
	int i;
	
	len = strlen(user_input);
	i = len - 1;
	while (i >= 0)
	{
		if ((i - 1 >= 0) && (is_logical_operator_char(user_input[i]) == TRUE))
		{
			if (get_logical_operator(user_input, i) != OPERATOR_NOT_FOUND)
			{
				printf("Logical operator found\n");
			}
			i--;
		}
		i--;
	}
}

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

int	get_logical_operator(char *user_input, int i)
{
	if (is_and_symbol(user_input[i]) && is_and_symbol(user_input[i - 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i]) && is_or_symbol(user_input[i - 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}






t_tree planteur(char *commande)
{
	
}