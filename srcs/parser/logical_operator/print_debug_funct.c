/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_funct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:35:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/22 13:44:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print2DUtil(t_btree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
	{
        printf(" ");
	}
	if (root->logic_op)
   		printf("%s\n", root->logic_op->symbol);
	else if (root->pipe_seq)
		printf("%s\n", root->pipe_seq->str);
	else if (root->token)
		printf("%s\n", root->pipe_seq->str);
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(t_btree *root)
{
    printf("\n");
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
/*
void	level_by_level_printing(t_btree *root)
{
	t_list	*q1;
	t_list	*q2;

	if (!root)
		return;
	q1 = NULL;
	q2 = NULL;
	ft_lstadd_back(&q1, ft_lstnew(root));
	while (q1 != NULL || q2 != NULL)
	{
		while (q1 != NULL)
		{
			root = q1->content;
			if (root->logic_op)
				printf("%s ", root->logic_op->symbol);
			else if (root->pipe_seq)
				printf("%s ", root->pipe_seq->str);
			ft_lstdelone_parser(&q1);
			if (root->left)
			{
				ft_lstadd_back(&q2, ft_lstnew(root->left));
			}
			if (root->right)
			{
				ft_lstadd_back(&q2, ft_lstnew(root->right));
			}
		}
		printf("\n");
		while (q2 != NULL)
		{
			root = q2->content;
			if (root->logic_op)
				printf("%s ", root->logic_op->symbol);
			else if (root->pipe_seq)
				printf("%s ", root->pipe_seq->str);
			ft_lstdelone_parser(&q2);
			if (root->left)
				ft_lstadd_back(&q1, ft_lstnew(root->left));
			if (root->right)
				ft_lstadd_back(&q1, ft_lstnew(root->right));
		}
		printf("\n");
	}
}

*/
void	printab_input_level(t_input_level	*input_level)
{
	int len = ft_strlen(input_level->input);
	for (int i = 0; i < len; i++)
	{
		printf("%c ", input_level->input[i]);
	}
	printf("\n");
	for (int j = 0; j < len; j++)
	{
		printf("%d ", input_level->level[j]);
	}
	printf("\n");
}
