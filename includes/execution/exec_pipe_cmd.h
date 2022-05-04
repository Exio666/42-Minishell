/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:04 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPE_CMD_H
# define EXEC_PIPE_CMD_H

# include "minishell.h"

int		len_av(char **argv);
void	exec_cmd(t_lst_token *token, t_lst_env **env_list);
int		exec_pipe_cmd(t_lst_token *token, t_lst_env **env_list, int nb_cmd);

#endif