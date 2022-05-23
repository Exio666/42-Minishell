/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:02:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 10:15:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pipe_sequence(char	*user_input, int start_index)
{
	char	*pipe_sequence;
	int		end_index;
	int		size_pipe_sequence;

	end_index = get_end_index_pipe_sequence(user_input, start_index);
	size_pipe_sequence = get_size_pipe_sequence(start_index, end_index);
	pipe_sequence = __ft_calloc(size_pipe_sequence + 1);
	if (user_input && (size_t)start_index < ft_strlen(user_input))
		ft_strlcpy(pipe_sequence, &user_input[start_index],
			size_pipe_sequence + 1);
	return (pipe_sequence);
}

int	get_size_pipe_sequence(int start_index, int end_index)
{
	return ((end_index - start_index) + 1);
}