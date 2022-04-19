/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:08:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/19 21:11:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "echo a && echo b '|| (echo c || echo d)' && echo e"

# include "minishell.h"

typedef struct s_lst_leaf_node
{
	struct s_lst_leaf_node	*next;
	void					*content;
} t_lst_leaf_node;

typedef struct s_pipe_sequence_token
{
	char	*str;
	int		len;
	int		*token_number;
}	t_pipe_sequence_token;


/*
t_token	*search_tok_pipe(char *pipe_sequence)
{
	int	i;

	i = 0;
	while (pipe_sequence[i])
	{
		
		i++;
	}
}
*/
int	is_separator(char c, char *separator)
{
	int i;

	i = 0;
	while (separator[i])
	{
		if (c == separator[i])
			return (1);
		i++;
	}
	return (0);
}

void	pipe_skipe_space(t_pipe_sequence_token *pipe_seq, int *index)
{
	if (is_space(pipe_seq->str[(*index)]))
	{
		while (pipe_seq->str[(*index)] && !is_space(pipe_seq->str[(*index)]))
		{
			pipe_seq->token_number[*index] = 0;
			(*index)++;
		}
	}
} 

int	main(int argc, char **argv)
{
	char **split;
	
	if (argc < 2)
	{
		printf("NEED_ARG\n");
		return (1);
	}
	printf("%s\n\n", argv[1]);
//	printf("%s\n", SEPARATORS);
//	tokenise_pipe_sequence(argv[1]);
	split = ft_split_pipe_seq(argv[1], "|<>");
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	printf("\n");
	return (0);
}