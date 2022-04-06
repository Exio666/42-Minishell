/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:45:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/06 14:38:28 by bsavinel         ###   ########.fr       */
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

/*
 *	Genral
 */

# include "struct_enum.h"
# include "define.h"
# include "all_lib.h"

/*
 *	Builtins
 */

#include "echo.h"
#include "exit.h"

/*
 *	Checker
 */

# include "and_or_checker.h"
# include "primary_checker.h"
# include "quote_checker.h"

/*
 *	Utils
 */

#include "jump_caracters.h"

/*
 *	Wilcard
 */


#endif