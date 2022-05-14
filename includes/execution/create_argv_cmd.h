/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_cmd.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:08:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 19:09:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ARGV_CMD_H
# define CREATE_ARGV_CMD_H

# include "minishell.h"

char	**create_argv_cmd(t_lst_token *token);

#endif