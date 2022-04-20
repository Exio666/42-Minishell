/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:08:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/20 06:24:51 by rpottier         ###   ########.fr       */
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


int	main(int argc, char **argv)
{
	char **split;
	
	if (argc < 2)
	{
		printf("NEED_ARG\n");
		return (1);
	}
	printf("%s\n\n", argv[1]);
	split = ft_split_pipe_seq(argv[1], "|<>");
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	printf("\n");
	__ft_calloc(-1);
	return (0);
}