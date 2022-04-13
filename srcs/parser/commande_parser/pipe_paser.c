/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:26:33 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/13 17:03:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
int	len_pipe(char *pipe_sequence, int index)
{
	int	len_pipe;

	len_pipe = 0;
	while (index > -1 && pipe_sequence[index] != '|')
	{
		len_pipe++;
		index--;
	}
	return (0);
}

char	*split_pipe(char *pipe_sequence, int index)
{
	int		len_pipe;
	char	*pipe;

	index--;
	len_pipe = len_pipe(pipe_sequence, index);
	if (len_pipe <= 0)
		return (NULL);
	pipe = __ft_calloc(sizeof(char) * len_pipe + 1);
	if (!pipe)
		return (NULL);
	pipe[len_pipe] = '\0';
	while (index > -1 && pipe_sequence[index] != '|')
	{
		pipe[len_pipe] = pipe_sequence[index];
		len_pipe--;
		index--;
	}
	return (pipe);
}

t_list **parser_pipe(char *pipe_sequence)
{
	int 	index;
	t_list	**start;

	index = 0;
	*start = NULL;
	while (pipe_sequence[index])
	{
		i = jump_caracters(pipe_sequence, "\"\'|", index, 1);
		skip_quote(pipe_sequence, &index);
		if (pipe_sequence[index] == '|')
			ft_lstadd_back(start, ft_lstnew((void *)parse_commande(split_pipe(pipe_sequence - 1, index))));
	}
	ft_lstadd_back(ft_lstnew(parse_commande(split_pipe(pipe_sequence, index))));
}
*/