/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:48:51 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:50:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_TOKEN_1_H
# define IS_TOKEN_1_H

int	is_redirect_in_token(char *str);
int	is_redirect_out_token(char *str);
int	is_redirect_out_append_token(char *str);
int	is_pipe_token(char *str);
int	is_here_doc_token(char *str);

#endif