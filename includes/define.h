/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:45:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/22 10:53:28 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "minishell.h"

# ifndef DEBUG
#  define DEBUG 1
# endif

/* execution.c */

# define ERROR_EXECVE -1
# define NO_ARG 0

# define RED		"\1\x1B[31m\2"
# define RED_BOLD	"\x1B[31m"
# define GRN		"\1\x1B[32m\2"
# define YEL		"\1\x1B[33m\2"
# define BLU		"\1\x1B[34m\2"
# define RESET		"\1\x1B[0m\2"

# define UI unsigned int

/*
 *	Logical operator
 */

# define COUNT 10
# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define OP_LOGIC 1
# define PIPE_SEQ 2

/*
 * tokenisation
 */

# define SEPARATORS "\'\"| "
# define PIPE_SEP '|'

/*
 * Error message
 */

# define S_ERROR_M_QUOTE "Syntax error : missing \'\'\'"
# define S_ERROR_M_DQUOTE "Syntax error : missing \'\"\'"
# define S_ERROR_M_OPEN_PAR "Syntax error : missing ')'"
# define S_ERROR_NP_CLOSE_PAR "Syntax error : no pattern for ')'"
# define S_ERROR_UNEX_TOK_AND "Syntax error : near unexpected token \'&&\'"
# define S_ERROR_UNEX_TOK_OR "Syntax error : near unexpected token \'||\'"
# define S_ERROR_UNEX_TOK_PIPE "Syntax error : near unexpected token \'|\'"
# define S_ERROR_UNEX_TOK_REDIRECT_OUT "Syntax error : \
near unexpected token \'>\'"
# define S_ERROR_UNEX_TOK_REDIRECT_IN "Syntax error : \
near unexpected token \'<\'"
# define S_ERROR_MIS_ARG_REDIRECT_IN "Syntax error : \
missing argument after \'<\'"
# define S_ERROR_MIS_ARG_REDIRECT_OUT "Syntax error : \
missing argument after \'>\'"
# define S_ERROR_MISSING_COMMANDE "Syntax error : missing commande"
# define CD_ERROR_NO_DIR "cd: no such file or directory: "
# define CD_ERROR_HOME_MOT_SET "cd: HOME not set\n"
# define CD_TOO_MANY_ARGS "cd: too many arguments\n"
# define S_ERROR_MIS_CMD_PIPE "syntax error near unexpected token \'|\'"
# define S_ERROR_CMD_PARENTHESE "syntax error need comande betwen \'(\' \')\'"

#endif