/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_pipe_sequence_in_tree.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:56:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:39:51 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_all_pipe_sequence_in_tree(t_btree **root, char *user_input)
{
	t_pipe_sequence	**splited_pipe_seq;

	remove_parenthesis(user_input);
	splited_pipe_seq = split_all_pipe_sequence(user_input);
	insert_all_pipe_seq_in_btree(root, splited_pipe_seq);
}

t_pipe_sequence	**split_all_pipe_sequence(char *user_input)
{
	t_pipe_sequence	**splited;
	int				nb_pipe_sequence;
	int				i;
	int				start_index;

	i = 0;
	nb_pipe_sequence = count_pipe_sequence(user_input);
	splited = __ft_calloc(sizeof(t_pipe_sequence *) * (nb_pipe_sequence + 1));
	while (i < nb_pipe_sequence)
	{
		splited[i] = __ft_calloc(sizeof(t_pipe_sequence));
		start_index = get_start_iuence(user_input, i);
		splited[i]->str = get_pipe_sequence(user_input, start_index);
		splited[i]->index = (unsigned int)start_index;
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

void	remove_parenthesis(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]) || is_double_quote(str[i]))
			skip_quote(str, &i);
		if (str[i] == '(' || str[i] == ')')
			str[i] = ' ';
		i++;
	}
}

int	count_pipe_sequence(char *user_input)
{
	int	nb_of_pipe_sequence;

	nb_of_pipe_sequence = count_logic_op(user_input) + 1;
	return (nb_of_pipe_sequence);
}
