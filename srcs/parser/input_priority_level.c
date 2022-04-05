/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prio_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:20:55 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 17:20:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_input_level	*attribute_level(char *user_input)
{
	int				level;
	int				i;
	t_input_level	*input_level;
	int				len;

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
	return (input_level);
}
/*	inserer cette fonction au dessus de - return (input_level);- 
** -> printab_input_level(input_level, len); // DEBUG */

t_input_level	*malloc_input_level(char *user_input)
{
	int				len;
	t_input_level	*input_level;

	len = strlen(user_input);
	input_level = calloc(1, sizeof(t_input_level));
	input_level->level = calloc(len, sizeof(int));
	return (input_level);
}

int	get_max_level(t_input_level	*input_level)
{
	int	i;
	int	max_level;
	int	input_len;

	input_len = strlen(input_level->input);
	i = 0;
	max_level = 0;
	while (i < input_len)
	{
		if (input_level->level[i] > max_level)
			max_level = input_level->level[i];
		i++;
	}
	return (max_level);
}

void	init_level(t_prio_level *level, t_input_level *input_level)
{
	level->max = get_max_level(input_level);
	level->current = 0;
}
