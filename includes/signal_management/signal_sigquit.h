/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sigquit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:50:58 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/15 20:19:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_SIGQUIT_H
# define SIGNAL_SIGQUIT_H

# include "minishell.h"

void	handler_sigquit_exit(int sig);
void	handler_sigquit_empty(int sig);

#endif