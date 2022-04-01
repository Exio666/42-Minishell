/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:19:13 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/01 16:35:41 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

/*
 *	Define
 */

# define FALSE 0
# define TRUE 1

# ifndef DEBUG
#  define DEBUG 1
# endif

/*
 *	Enumeration
 */

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

/*
 *	Structure
 */

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

#endif