/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 17:28:30 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define COUNT 10
# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define FALSE 0
# define TRUE 1
# define UI unsigned int

typedef struct s_logical_op
{
	char	symbol[3];
	UI		type;
	UI		index;
}	t_logic_op;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	t_logic_op		*logic_op;
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
}	t_prio_level;

typedef struct s_input_prio_level
{
	char	*input;
	int		*level;
}	t_input_level;

/*----- list_management.c -----*/

t_list			*lstnew(t_btree *elem);
t_list			*lstlast(t_list *lst);
void			lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **lst);

/*----- input_prio_level.c -----*/

t_input_level	*attribute_level(char *user_input);
t_input_level	*malloc_input_level(char *user_input);
int				get_max_level(t_input_level	*input_level);
void			init_level(t_prio_level *level, t_input_level *input_level);

/*----- logical_operator_indexation.c -----*/

t_logic_op		*get_current_log_op(int actual_op_index, t_logic_op **logical_op);
t_logic_op		**malloc_logical_op_reference(char *user_input);
t_logic_op		**create_logical_op_array(char *user_input);


/*----- btree_management.c -----*/

void			insert_logic_op(t_btree	**btree, int actual_op_index, t_logic_op **logical_op);
int				cmp_index_logical_op(UI actual_op_index, UI index_node);
void			btree_insert(t_btree **root, t_logic_op *logical_op, int (*cmpf)(UI ,UI ));
t_btree			*btree_create_node(void *item);

/*----- get_logic_op.c -----*/

int				get_logic_op_from_end(char *user_input, int i);
int				get_logic_op_from_begin(char *user_input, int i);

/*----- count_and_update_logic_op.c------*/

void			update_logical_op(t_logic_op *logical_op, int position, int actual_log_op);
int				count_logic_op(char *user_input);

/*----- find_specific_char_funct.c -----*/

int				is_logical_op_char(char c);
int				is_and_symbol(char c);
int				is_or_symbol(char c);
int				is_open_parenthesis(char c);
int				is_close_parenthesis(char c);

/*----- parser_logical_op.c -----*/

void			logical_op_parser(t_logic_op **logical_op, t_input_level *input_level);	
int				priority_levels_remaining(int actual_level, int level_max);
int				actual_level_not_fully_checked(int i);
int				is_part_of_actual_level(int char_level, int actual_level);
int				logical_op_type_is_found(int logical_op_type);

/*----- debug_print_funct.c -----*/

void			print2DUtil(t_btree *root, int space);
void			print2D(t_btree *root);
void			printab_input_level(t_input_level	*input_level, int len);
void			level_by_level_printing(t_btree *root);
#endif