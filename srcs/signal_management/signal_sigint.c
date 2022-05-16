/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sigint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:35:52 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 17:04:04 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint_prompt(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handler_sigint_empty(int sig)
{
	(void)sig;
	g_exit_status = 386;
}

void	handler_sigint_heredoc(int sig)
{
	(void)sig;
	free_all();
	exit(1);
}
