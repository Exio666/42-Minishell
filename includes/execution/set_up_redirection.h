/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_redirection.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:48:23 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/03 11:56:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UP_REDIRECTION_H
# define SET_UP_REDIRECTION_H

void	redirect_out(t_lst_token *token);
void	redirect_out_append(t_lst_token *token);
void	set_up_redirect_out(t_lst_token *token);
void	set_up_redirect_in(t_lst_token *token);

#endif