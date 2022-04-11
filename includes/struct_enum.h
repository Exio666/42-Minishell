/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:19:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/08 13:24:05 by bsavinel         ###   ########.fr       */
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
 *	Environement
 */

typedef struct s_lst_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}	t_lst_env;

/*
 *	primary checker
 */

typedef struct s_checker
{
	int		index;
	t_bool	error;
	char	*str;
	int		par_lvl;
}	t_checker;

/*
 *	Parsing AND/OR
 */

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
	void			*content;
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

#endif