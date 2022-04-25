/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_checker.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:21:24 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/25 10:26:11 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_CHECKER_H
# define REDIRECTION_CHECKER_H

void	redirect_out_checker(char *commande, t_checker *check);
void	redirect_in_checker(char *commande, t_checker *check);
void	pipe_content_checker(char *commande, t_checker *check);
int		redirection_checker(char *pipe_sequence, t_checker *check);

#endif