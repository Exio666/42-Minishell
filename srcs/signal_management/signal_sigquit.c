/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sigquit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:46:30 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 11:04:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigquit_exit(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}

void	handler_sigquit_empty(int sig)
{
	(void)sig;
}
