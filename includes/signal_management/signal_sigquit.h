/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sigquit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:50:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 10:51:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_SIGQUIT_H
# define SIGNAL_SIGQUIT_H

#include "minishell.h"

void	handler_sigquit_exit(int sig);
void	handler_sigquit_empty(int sig);

#endif