/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:45:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/31 17:25:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define FALSE 0
# define TRUE 1

# ifndef DEBUG
#  define DEBUG 1
# endif

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