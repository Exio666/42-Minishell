/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:12:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 21:46:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	increase_level(int *level)
{
	*level = *level + 1;
}

void	decrease_level(int *level)
{
	*level = *level - 1;
}
