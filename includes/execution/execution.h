/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:34:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/03 16:05:39 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "cmd_exec_utils.h"
# include "find_token_cmd.h"
# include "token_utils.h"
# include "set_up_redirection.h"

void	execute_command_tree(t_btree *root, t_lst_env *env_list);
void	execute_pipe_sequence(t_lst_token *token, t_lst_env *env_list);
void	execute_command(t_lst_token *token, t_lst_env *env_list);
char	*dup_without_extra_space_quote(char *str);
#endif
