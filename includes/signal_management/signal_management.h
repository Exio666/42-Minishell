/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:49:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 15:59:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_MANAGEMENT_H
# define SIGNAL_MANAGEMENT_H

# include "minishell.h"

void	handler_sigint_empty(int sig);
void	handler_sigint_prompt(int sig);
void	handler_sigint_endl(int sig);
void	handler_sigquit_exit(int sig);
void	handler_sigquit_empty(int sig);
void	handler_sigint_empty_no_prompt(int sig);

#endif