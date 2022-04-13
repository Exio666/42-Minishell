/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:56:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/13 17:13:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void remove_parenthesis(char *str)
{
	int i;

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

int main(int argc, char	**argv)
{
	(void)(argc);
	remove_parenthesis(argv[1]);
	char	**splited_pipe_seq = split_all_pipe_sequence(argv[1]);
	
	print_char_two_dim_array(splited_pipe_seq);
	return (0);
}


/*
void	btree_insert_pipe_sequence(t_btree **root,
	t_pipe_sequence *pipe_sequence, int (*cmpf)(UI, UI))
{
	if (*root == NULL)
		*root = btree_create_node(pipe_sequence);
	else if ((*cmpf)(pipe_sequence->index, (*root)->logic_op->index) <= 0)
		btree_insert_log_op(&(*root)->left, pipe_sequence, cmpf);
	else
		btree_insert_log_op(&(*root)->right, pipe_sequence, cmpf);
}
*/
int		count_pipe_sequence(char *user_input)
{
	int	nb_of_pipe_sequence;

	nb_of_pipe_sequence = count_logic_op(user_input) + 1;
	return (nb_of_pipe_sequence);
}

int	get_pipe_sequence_end_index(char	*user_input, int start_index)
{
	int	i;

	i = start_index;
	while (user_input[i] && !is_log_op(user_input, i))
		i++;
	return (i - 1);
}


int	is_log_op(char *user_input, int i)
{
	int	logical_op;

	if (is_logical_op_char(user_input[i]))
	{
		logical_op = get_logic_op_from_begin(user_input, i);
		if (logical_op_type_is_found(logical_op))
			return (TRUE);
	}
	return (FALSE);
}

int	get_size_pipe_sequence(int start_index, int end_index)
{
	return ((end_index - start_index) + 1);
}

char	*get_pipe_sequence(char	*user_input, int start_index)
{
	char	*pipe_sequence;
	int		end_index;
	int		size_pipe_sequence;

	end_index = get_pipe_sequence_end_index(user_input, start_index);
	size_pipe_sequence = get_size_pipe_sequence(start_index, end_index);
	pipe_sequence = __ft_calloc(size_pipe_sequence + 1);
	ft_strlcpy(pipe_sequence, &user_input[start_index], size_pipe_sequence + 1);
	return (pipe_sequence);
}

int		get_start_index(char *user_input, int pipe_sequence_to_find)
{
	int start_index;
	int current_pipe_seq;

	start_index = 0;
	current_pipe_seq = 0;
	while (user_input[start_index] && current_pipe_seq < pipe_sequence_to_find)
	{
		if (is_log_op(user_input, start_index))
		{
			start_index += 2;
			current_pipe_seq++;
		}
		else
			start_index++;
	}	
	return (start_index);
}

char	**split_all_pipe_sequence(char *user_input)
{
	char	**splited_pipe_seq;
	int		nb_pipe_sequence;
	int		index_pipe_seq;
	int		start_index;

	
	index_pipe_seq = 0;
	nb_pipe_sequence = count_pipe_sequence(user_input);
	splited_pipe_seq = __ft_calloc(sizeof(char*) * nb_pipe_sequence);
	while (index_pipe_seq < nb_pipe_sequence)
	{
		start_index = get_start_index(user_input, index_pipe_seq);
		splited_pipe_seq[index_pipe_seq] = get_pipe_sequence(user_input, start_index);
		index_pipe_seq++;
	}
	return (splited_pipe_seq);
}

void	insert_all_pipe_seq_in_btree(char *user_input)
{
	char	**all_pipe_sequence;

	all_pipe_sequence = split_all_pipe_sequence(user_input);
	
}