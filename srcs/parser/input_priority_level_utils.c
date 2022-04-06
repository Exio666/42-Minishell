/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:12:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/06 15:50:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_level(int *level)
{
	*level = *level + 1;
}

void	decrease_level(int *level)
{
	*level = *level - 1;
}
