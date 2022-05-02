/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:19:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/02 19:13:38 by bsavinel         ###   ########.fr       */
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
	TOK_WORD,
	TOK_REDIRECT_IN,			// <
	TOK_REDIRECT_OUT,			// >
	TOK_REDIRECT_OUT_APPEND,	// >>
	TOK_HEREDOC,				// <<
	TOK_PIPE,					// |
	TOK_SINGLE_QUOTE,			// '
	TOK_DOUBLE_QUOTE,			// '
	TOK_DOLLAR,					// $

	
	TOK_AND,
	TOK_OR,
	TOK_OPEN_PARENTHESIS,
	TOK_CLOSE_PARENTHESIS,
	TOK_PIPE_SEQUENCE
}	t_type_token;

typedef enum e_btree_item_type
{
	LOGIC_OPERATOR
} t_btree_item_type;

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

typedef struct s_pipe_sequence
{
	char			*str;
	unsigned int	index;
}	t_pipe_sequence;

typedef struct s_token
{
	char			*str;
	t_type_token	type;
}	t_token;


typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_lst	*list;
	t_pipe_sequence	*pipe_seq;
	t_logic_op		*logic_op;
	struct s_list	*token_list;
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

/*
 *	Wildcard
 */

typedef struct s_wildcard
{
	int		str_in_simple_quote;
	int		str_in_double_quote;
	int		wild_in_simple_quote;
	int		wild_in_double_quote;
}	t_wildcard;

#endif