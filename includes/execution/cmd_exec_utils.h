/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:54:06 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/11 01:08:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXEC_UTILS_H
# define CMD_EXEC_UTILS_H

# include "minishell.h"

int		ft_size_2d_array(char **array);
void	insert_split_in_token_list(t_lst_token *token, char **split);
void	tokenisation_post_expand(t_lst_token *token);
char	**create_argv_cmd(t_lst_token *token);

#endif
