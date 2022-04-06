/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level_utils.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:23 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 20:15:05 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PRIORITY_LEVEL_UTILS_H
# define INPUT_PRIORITY_LEVEL_UTILS_H

# include "../includes/parser.h"

void	increase_level(int *level);
void	decrease_level(int *level);

#endif