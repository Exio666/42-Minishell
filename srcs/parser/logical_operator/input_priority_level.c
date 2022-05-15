/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:00:35 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 16:00:38 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** input example:
** ./a.out "a && b && (c || (d && e) || f) || (g && h)"
** output:
** a && b && (c || (d && e) || f) || (g && h) 
** 000000000001111112222222111111000001111111 
*/

t_input_level	*attribute_level_parenthesis(char *user_input)
{
	int				quote_skiped;
	int				level;
	int				i;
	t_input_level	*input_level;

	input_level = malloc_input_level(user_input);
	input_level->input = ft_strdup(user_input);
	i = 0;
	level = 0;
	while (input_level->input[i])
	{
		quote_skiped = FALSE;
		input_level->level[i] = level;
		if (is_quote(input_level->input[i]))
			quote_skiped = skip_quote(input_level->input, &i);
		if (input_level->input[i]
			&& is_open_parenthesis(input_level->input[i]))
			increase_level(&level);
		else if (input_level->input[i]
			&& is_close_parenthesis(input_level->input[i]))
			decrease_level(&level);
		if (input_level->input[i] && quote_skiped == FALSE)
			i++;
	}
	return (input_level);
}

t_input_level	*malloc_input_level(char *user_input)
{
	int				i;
	int				len;
	t_input_level	*input_level;

	len = ft_strlen(user_input);
	input_level = __ft_calloc(sizeof(t_input_level));
	input_level->level = __ft_calloc(len * sizeof(int));
	i = 0;
	while (i < len)
	{
		input_level->level[i] = -1;
		i++;
	}		
	return (input_level);
}

int	get_max_level(t_input_level	*input_level)
{
	int	i;
	int	max_level;
	int	input_len;

	input_len = ft_strlen(input_level->input);
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
