/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level_utils.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:23 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 10:48:59 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PRIORITY_LEVEL_UTILS_H
# define INPUT_PRIORITY_LEVEL_UTILS_H

# include "minishell.h"

void	increase_level(int *level);
void	decrease_level(int *level);

#endif