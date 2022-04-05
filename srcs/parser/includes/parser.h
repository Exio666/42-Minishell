/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:09:10 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 20:13:56 by rpottier         ###   ########.fr       */
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

# include "btree_management.h"
# include "count_and_update_logic_op.h"
# include "find_specific_char_funct.h"
# include "get_logical_op.h"
# include "input_priority_level.h"
# include "input_priority_level_utils.h"
# include "list_management.h"
# include "logical_operator_indexation.h"
# include "parser_logical_op.h"
# include "print_debug_funct.h"

#endif