/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipe_sequence.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:32:07 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 16:52:45 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char	**argv)
{
	t_btree	*root;
	
	//if (argc < 2)
	//{
//		printf("NEED ARG\n");
//		return (0);
//	}
	(void)(argv);
	(void)(argc);
	char str[]= "echo a && echo (&& ||)\"";
//	char	*str = argv[1];
	root = get_btree_of_logical_op(str);
	add_all_pipe_sequence_in_tree(&root, str);
//	print2D(root);
	__ft_calloc(-1);
	return (0);
}
