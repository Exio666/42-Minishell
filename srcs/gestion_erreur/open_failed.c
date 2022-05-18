/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:52:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/18 08:36:34 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_failed(char *str, int child)
{
	perror(str);
	if (child)
	{
		__ft_calloc(-1);
		rl_clear_history();
		exit(1);
	}
	return (1);
}
