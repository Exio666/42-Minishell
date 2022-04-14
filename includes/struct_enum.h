/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:19:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 15:48:02 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ENUM_H
# define STRUCT_ENUM_H

# include "minishell.h"

/**********************
***   Enumeration   ***
**********************/

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef enum e_type_token
{
	OPEN_PARENTHESIS,
	CLOSE_PARENTHESIS,
	PIPE_SEQUENCE,
	OR,
	AND
}	t_type_token;

typedef enum e_type_command
{
	COMMANDE,
	NO_TOKEN,
	PIPE,
	OPTION,
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	ENV_VARIABLE,
	REDIRECT_IN,
	REDIRECT_OUT_TRUNC,
	REDIRECT_OUT_APPEND,
	HERE_DOC,
	WILDCARD
}	t_type_command;

/********************
***	  Structure   ***
********************/

typedef struct s_commande
{
	t_type_command		type_command;
	struct s_commande	*next;
	char				*content;
}	t_command;

typedef struct s_token
{
	t_type_token	type_token;
	struct s_token	*next;
	t_command		**content;
}	t_token;


/*
 *	primary checker
 */

typedef struct s_checker
{
	int		index;
	t_bool	error;
	char	*str;
	int		par_lvl;
	int		arg_of_redirect;
}	t_checker;

/*
 *	Parsing AND/OR
 */



/*
 *	env_list
 */

typedef struct s_lst_env
{
	char				*name;
	char				*content;
	struct s_lst_env	*next;
	struct s_lst_env	*prev;
}	t_lst_env;

/*
 *	parser
 */

typedef struct s_logical_op
{
	char			symbol[3];
	unsigned int	type;
	unsigned int	index;
}	t_logic_op;

typedef	struct s_pipe_sequence
{
	char			*str;
	unsigned int	index;
}	t_pipe_sequence;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	t_pipe_sequence	*pipe_seq;
	t_logic_op		*logic_op;
	int				item_type;
}	t_btree;

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

#endif