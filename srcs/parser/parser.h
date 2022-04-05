/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 14:41:33 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COUNT 10

typedef struct s_logical_op
{
	char			symbol[3];
	UI	type;
	UI	begin_position;
}	t_logical_op;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	t_logical_op	*logical_op;
}	t_btree;

typedef struct s_list
{
	struct s_list	*next;
	t_btree			*elem;
}	t_list;

typedef struct s_priority_level
{
	int		current;
	int		max;
}	t_priority_level;

typedef struct s_input_priority_level
{
	char	*input;
	int		*level;
}	t_input_priority_level;


typedef enum e_type_token
{
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
	PIPE_SEQUENCE,
	OR,
	AND
}	t_type_token;

# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define FALSE 0
# define TRUE 1
# define UI unsigned int

t_list			*lstlast(t_list *lst);
int				get_max_level(t_input_priority_level	*input_level);
t_list			*lstnew(t_btree *elem);
void			lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **lst);
void			level_by_level_printing(t_btree *root);
void			btree_insert_data(t_btree **root, t_logical_op *logical_op, int (*cmpf)(UI ,UI ));
t_btree			*btree_create_node(void *item);
void			parser(t_logical_op **logical_op, t_input_priority_level *input_level, int level_max);
int				cmp_index_logical_op(UI actual_op_begin_position, UI begin_position_node);
t_logical_op	*get_current_log_op(int actual_op_begin_position, t_logical_op **logical_op);
t_logical_op	**malloc_logical_op_reference(char *user_input);
t_logical_op	**create_logical_op_array(char *user_input);
void			update_logical_op(t_logical_op *logical_op, int position, int actual_log_op);
int				count_logical_op(char *user_input);
int				is_logical_operator_char(char c);
int				is_and_symbol(char c);
int				is_or_symbol(char c);
int				get_logical_op_from_end(char *user_input, int i);
int				get_logical_op_from_begin(char *user_input, int i);
t_input_priority_level *malloc_input_level(char *user_input);
int				is_open_parenthesis(char c);
int				is_close_parenthesis(char c);
t_input_priority_level	*attribute_level(char *user_input);
void			printab_input_level(t_input_priority_level	*input_level, int len);


void			logical_op_parser(t_logical_op **logical_op, t_input_priority_level *input_level, int level_max);
int				priority_levels_remaining(int actual_level, int level_max);
int				actual_level_not_fully_checked(int i);
int				is_part_of_actual_level(int char_level, int actual_level);
int				logical_op_type_is_found(int logical_op_type);
void			insert_logic_op_in_tree(t_btree	**btree, int actual_op_begin_position, t_logical_op **logical_op);

void			print2DUtil(t_btree *root, int space);
void			print2D(t_btree *root);
void			level_by_level_printing(t_btree *root);
#endif