/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:46:30 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/05 16:31:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint_prompt(int sig)
{
	const char	prompt[] = GRN "\nBsavinel_and_associates_shell$ " RESET;

	(void)sig;
	ft_putstr_fd((char *)prompt, 2);
}

void	handler_sigint_endl(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 2);
}

void	handler_sigint_empty(int sig)
{
	(void)sig;
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