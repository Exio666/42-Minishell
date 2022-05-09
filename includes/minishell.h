/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:45:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 17:59:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 *	Libraries
 */

# include <signal.h>
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
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>

/*
 *	General
 */

# include "struct_enum.h"
# include "define.h"
# include "all_lib.h"

/*
 *	heredoc.h
 */

# include "heredoc.h"

/*
 *	Gestion Erreur
 */

# include "gestion_erreur.h"

/*
 *	Builtins
 */

# include "builtins.h"

/*
 *	btree_management
 */

# include "btree_management.h"

/*
 *	Checker
 */

# include "checker.h"

/*
 *	Env
 */

# include "get_all_path.h"
# include "list_to_tab.h"
# include "ft_get_env.h"

/*
 *	Parser
 */
/*
# include "btree_management.h"
# include "count_and_update_logic_op.h"
# include "find_specific_char_funct.h"
# include "get_logical_op.h"
# include "input_priority_level.h"
# include "input_priority_level_utils.h"
# include "list_management.h"
# include "logical_operator_indexation.h"
# include "parse_op_by_level.h"
# include "print_debug_funct.h"
# include "get_btree_of_logical_op.h"
*/
# include "logical_operator.h"
# include "pipe_sequence.h"   

/*
 *	Env_list
 */

# include "env_list.h"

/*
 *	Builtins
 */

# include "builtins.h"

/*
 * tokenisation
 */

# include "pipe_seq_to_token_list.h"

/*
 *	Utils
 */

# include "jump_caracters.h"
# include "is_functions.h"

/*
 *	Wilcard
 */

# include "expand.h"
# include "execution.h"

/*
 *	Signal
 */

# include "signal_management.h"

#endif