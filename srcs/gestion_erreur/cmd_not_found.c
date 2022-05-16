/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:58:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 16:39:09 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_not_found(char *cmd)
{
	if (isatty(STDIN_FILENO))
	{	
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : command not found\n", 2);
	}
}
