/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipe_sequence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:32:07 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:40:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char	**argv)
{
	t_btree	*root;

	if (argc < 2)
	{
		printf("NEED ARG\n");
		return (0);
	}
	root = get_btree_of_logical_op(argv[1]);
	add_all_pipe_sequence_in_tree(&root, argv[1]);
	print2D(root);
	__ft_calloc(-1);
	return (0);
}
