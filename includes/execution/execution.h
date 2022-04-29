/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:34:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 15:51:20 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 15:30:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_tree(t_btree *root, t_lst_env *env_list);
void	execute_pipe_sequence(t_lst_token *token, t_lst_env *env_list);
void	execute_command(t_lst_token *token, t_lst_env *env_list);
char	**find_cmd(t_lst_token *token);
char	**create_argv_cmd(t_lst_token *token);
void	expand(t_lst_token *token, t_lst_env *env_list);
t_lst_token	*find_next_cmd(t_lst_token *token);
int		is_redirect_token(t_type_token token_type);
int		is_heredoc_token(t_type_token token_type);
t_lst_token	*skip_two_token(t_lst_token *token);

#endif