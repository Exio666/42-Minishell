/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:46:30 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 16:03:29 by bsavinel         ###   ########.fr       */
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

void	handler_sigint_endl(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ft_putchar_fd('\n', 2);
}

void	handler_sigint_empty(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ft_putchar_fd('\n', 2);
}

void	handler_sigint_empty_no_prompt(int sig)
{
	(void)sig;
	g_exit_status = 130;
	ft_putchar_fd('\n', 2);
}

void	handler_sigquit_exit(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit (core dumped)\n", 2);
}

void	handler_sigquit_empty(int sig)
{
	(void)sig;
}
