/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_failed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:52:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 14:32:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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