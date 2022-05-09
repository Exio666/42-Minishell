/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_redirection.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:48:23 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/09 16:10:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_UP_REDIRECTION_H
# define SET_UP_REDIRECTION_H

int	redirect_out(t_lst_token *token, int child);
int	redirect_out_append(t_lst_token *token, int child);
int	redirect_in(t_lst_token *token, int child);
int	set_up_redirect(t_lst_token *token, int child);

#endif