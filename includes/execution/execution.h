/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:34:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 17:05:02 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "cmd_exec_utils.h"
# include "find_token_cmd.h"
# include "token_utils.h"
# include "set_up_redirection.h"
# include "count_pipe.h"
# include "exec_builtins.h"
# include "exec_pipe_cmd.h"
# include "count_pipe.h"
# include "main_execution.h"

void	execute_command_tree(t_btree *root, t_lst_env **env_list);
void	execute_command(t_lst_token *token, t_lst_env **env_list);
int		exec_one_cmd(char **argv, t_lst_env **env_list);

#endif
