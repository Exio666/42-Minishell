/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:35:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 14:38:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define COUNT 10

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
        printf(" ");
    printf("%s\n", root->logical_op->symbol);
 
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

void	level_by_level_printing(t_btree *root)
{
	t_list	*q1;
	t_list	*q2;

	if (!root)
		return;
	q1 = NULL;
	q2 = NULL;
	lstadd_back(&q1, lstnew(root));
	while (q1 != NULL || q2 != NULL)
	{
		while (q1 != NULL)
		{
			root = q1->elem;
			printf("%s ", root->logical_op->symbol);
			ft_lstdelone(&q1);
			if (root->left)
			{
				lstadd_back(&q2, lstnew(root->left));
			}
			if (root->right)
			{
				lstadd_back(&q2, lstnew(root->right));
			}
		}
		printf("\n");
		while (q2 != NULL)
		{
			root = q2->elem;
			printf("%s ", root->logical_op->symbol);
			ft_lstdelone(&q2);
			if (root->left)
				lstadd_back(&q1, lstnew(root->left));
			if (root->right)
				lstadd_back(&q1, lstnew(root->right));
		}
		printf("\n");
	}
}