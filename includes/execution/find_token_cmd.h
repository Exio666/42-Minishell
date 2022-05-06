/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token_cmd.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:50:38 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:19 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_TOKEN_CMD_H
# define FIND_TOKEN_CMD_H

# include "minishell.h"

t_lst_token	*find_first_token_cmd(t_lst_token *token);
t_lst_token	*find_first_token_next_cmd(t_lst_token *token);

#endif
