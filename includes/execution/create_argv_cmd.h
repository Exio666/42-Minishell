/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_cmd.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:08:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 08:53:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ARGV_CMD_H
# define CREATE_ARGV_CMD_H

# include "minishell.h"

void	insert_str_in_array(t_lst_token	*copie, char **argv, int *i, int *j);
char	**create_argv_cmd(t_lst_token *token);

#endif