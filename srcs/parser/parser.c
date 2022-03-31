/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:24:05 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/31 17:56:42 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, const char * argv[])
{
	char *user_input;

	user_input = readline(NULL);
	parser(user_input);
	return 0;
}

void parser(char *user_input)
{
	
}


