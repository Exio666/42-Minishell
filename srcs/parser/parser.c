/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:41:57 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 15:07:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	main(int argc, char **argv)
{
	t_logical_op			**logical_op;
	t_input_priority_level	*input_level;
	int						max_level;

	input_level = attribute_level(argv[1]);
	max_level = get_max_level(input_level);
	logical_op = create_logical_op_array(argv[1]);
	logical_op_parser(logical_op, input_level, max_level);
	return (0);
}

int	get_max_level(t_input_priority_level	*input_level)
{
	int	i;
	int	max_level;
	int	input_len;

	input_len = strlen(input_level->input);
	i = 0;
	max_level = 0;
	while (i < input_len)
	{
		if (input_level->level[i] > max_level)
			max_level = input_level->level[i];
		i++;
	}
	return (max_level);
}

t_list	*lstlast(t_list *lst)
{
	if (lst)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

t_list	*lstnew(t_btree *elem)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	new_elem->elem = elem;
	new_elem->next = NULL;
	return (new_elem);
}

void	lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		tmp = lstlast(*alst);
		tmp->next = new;
	}
}
void	ft_lstdelone(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	free(tmp);
}

void	btree_insert_data(t_btree **root, t_logical_op *logical_op, int (*cmpf)(unsigned int ,unsigned int ))
{
	if (*root == NULL)
		*root = btree_create_node(logical_op);
	else if ((*cmpf)(logical_op->begin_position, (*root)->logical_op->begin_position) < 0)
		btree_insert_data(&(*root)->left, logical_op, cmpf);
	else
		btree_insert_data(&(*root)->right, logical_op, cmpf);
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;
	
	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->logical_op = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	priority_levels_remaining(int actual_level, int level_max)
{
	if (actual_level <= level_max)
		return (1);
	else
		return (0);
}

int	actual_level_not_fully_checked(int i)
{
	if (i >= 0)
		return (1);
	else
		return (0);
}

int	is_part_of_actual_level(int char_level, int actual_level)
{
	if (char_level == actual_level)
		return (1);
	else
		return (0);
}
int	logical_op_type_is_found(int logical_op_type)
{
	if (logical_op_type == OPERATOR_NOT_FOUND)
		return(0);
	return (1);
}

void	insert_logic_op_in_tree(t_btree	**btree, int actual_op_begin_position, t_logical_op **logical_op)
{
	t_logical_op *current_log_op;

	current_log_op = get_current_log_op(actual_op_begin_position, logical_op);
	btree_insert_data(btree, current_log_op, cmp_index_logical_op);
}

void	init_level(t_priority_level *level, t_input_priority_level *input_level)
{
	level->max = get_max_level(input_level);
	level->current = 0;
}




void	logical_op_parser(t_logical_op **logical_op, t_input_priority_level *input_level, int level_max)
{
	t_btree				*btree;
	t_priority_level	level;
	t_logical_op		cur_op;
	int					i;

	init_level(&level, input_level);
	btree = NULL;
	while (priority_levels_remaining(level.current, level_max))
	{
		i = strlen(input_level->input) - 1;
		while (actual_level_not_fully_checked(i))
		{
			if (is_part_of_actual_level(input_level->level[i], level.current)
				&& is_logical_operator_char(input_level->input[i]))
			{
				cur_op.type = get_logical_op_from_end(input_level->input, i);
				if (logical_op_type_is_found(cur_op.type))
					insert_logic_op_in_tree(&btree, i - 1, logical_op);
				i--;
			}
			i--;
		}
		level.current++;
	}
//	print2D(btree);
}

int	cmp_index_logical_op(unsigned int actual_op_begin_position, unsigned int begin_position_node)
{
	if (actual_op_begin_position < begin_position_node)
		return (-1);
	else
		return (1);
}

t_logical_op	*get_current_log_op(int actual_op_begin_position, t_logical_op **logical_op)
{
	int	i;

	i = 0;
	while (logical_op[i])
	{
		if (actual_op_begin_position == logical_op[i]->begin_position)
			return (logical_op[i]);
		i++;
	}
	return (NULL);
}

t_logical_op	**malloc_logical_op_reference(char *user_input)
{
	t_logical_op	**logical_op;
	int				size;
	int				i;

	i = 0;
	if (user_input == NULL)
		return (NULL);
	size = count_logical_op(user_input);
	logical_op = calloc(size + 1, sizeof(t_logical_op*)); // WARNING CALLOC!!!!
	if (logical_op == NULL)
		return (NULL);
	while (i < size)
	{
		logical_op[i] = calloc(1, sizeof(t_logical_op));
		if (logical_op[i] == NULL)
			return (NULL);
		i++;
	}
	return (logical_op);
}

t_logical_op	**create_logical_op_array(char *user_input)
{
	t_logical_op	**logical_op;
	int				actual_log_op;
	int				i;
	int				j;

	logical_op = malloc_logical_op_reference(user_input);
	if (logical_op == NULL)
		printf("FAIL 0\n");
	i = 0;
	j = 0;
	while (user_input[i] && user_input[i + 1])
	{
		if (user_input[i] && user_input[i + 1] && is_logical_operator_char(user_input[i]) == TRUE)
		{
			actual_log_op = get_logical_op_from_begin(user_input, i);
			if (actual_log_op != OPERATOR_NOT_FOUND)
			{
				update_logical_op(logical_op[j], i, actual_log_op);
				j++;
			}
			i++;
		}
		i++;
	}
	return (logical_op);
}

void	update_logical_op(t_logical_op *logical_op, int position, int actual_log_op)
{	
	logical_op->begin_position = position;
	logical_op->type = actual_log_op;
	if (actual_log_op == AND_OPERATOR)
	{
		logical_op->symbol[0] = '&';
		logical_op->symbol[1] = '&';
	}
	else if (actual_log_op == OR_OPERATOR)
	{
		logical_op->symbol[0] = '|';
		logical_op->symbol[1] = '|';
	}
}

int	count_logical_op(char *user_input)
{	
	int	actual_logical_op;
	int	logical_op_count;
	int	i;

	if (user_input == NULL)
		return (-1);
	i = 0;
	logical_op_count = 0;
	while (user_input[i + 1])
	{
		if (user_input[i + 1] && is_logical_operator_char(user_input[i]) == TRUE)
		{
			actual_logical_op = get_logical_op_from_begin(user_input, i);
			if (actual_logical_op != OPERATOR_NOT_FOUND)
				logical_op_count++;
			i++;
		}
		i++;
	}
	return (logical_op_count);
}

int	is_logical_operator_char(char c)
{
	if (c == '&' || c == '|')
		return (TRUE);
	else
		return (FALSE);
}

int	is_and_symbol(char c)
{
	if (c == '&')
		return (TRUE);
	else
		return (FALSE);
}
int	is_or_symbol(char c)
{
	if (c == '|')
		return (TRUE);
	else
		return (FALSE);	
}

int	get_logical_op_from_end(char *user_input, int i)
{
	if (is_and_symbol(user_input[i]) && is_and_symbol(user_input[i - 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i]) && is_or_symbol(user_input[i - 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}

int	get_logical_op_from_begin(char *user_input, int i)
{
	if (is_and_symbol(user_input[i]) && is_and_symbol(user_input[i + 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i]) && is_or_symbol(user_input[i + 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}

t_input_priority_level	*malloc_input_level(char *user_input)
{
	int						len;
	t_input_priority_level	*input_level;

	len = strlen(user_input);
	input_level = calloc(1, sizeof(t_input_priority_level));
	input_level->level = calloc(len, sizeof(int));
	return(input_level);
}

int	is_open_parenthesis(char c)
{
	if (c == '(')
		return (TRUE);
	else
		return (FALSE);
}

int	is_close_parenthesis(char c)
{
	if (c == ')')
		return (TRUE);
	else
		return (FALSE);
}

t_input_priority_level	*attribute_level(char *user_input)
{
	int						level;
	int						i;
	t_input_priority_level	*input_level;

	int	len;
	len = strlen(user_input);
	input_level = malloc_input_level(user_input);
	input_level->input = strdup(user_input);
	i = 0;
	level = 0;
	while (input_level->input[i])
	{
		input_level->level[i] = level;
		if (is_open_parenthesis(input_level->input[i]))
		{
			level++;
		}
		else if (is_close_parenthesis(input_level->input[i]))
		{
			level--;
		}
		i++;
	}
//	printab_input_level(input_level, len); // DEBUG
	return (input_level);
}

void	printab_input_level(t_input_priority_level	*input_level, int len)
{
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