/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:54:06 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/08 22:30:20 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXEC_UTILS_H
# define CMD_EXEC_UTILS_H

# include "minishell.h"

void	expand_command(t_lst_token *token, t_lst_env *env_list);
void	tokenisation_post_expand(t_lst_token *token);
char	**create_argv_cmd(t_lst_token *token);

#endif
