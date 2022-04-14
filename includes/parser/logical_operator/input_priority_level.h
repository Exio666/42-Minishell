/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_priority_level.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:32 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 14:32:42 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PRIORITY_LEVEL_H
# define INPUT_PRIORITY_LEVEL_H

# include "minishell.h"

/*----- input_prio_level.c -----*/

t_input_level	*attribute_level(char *user_input);
t_input_level	*malloc_input_level(char *user_input);
int				get_max_level(t_input_level	*input_level);
void			init_level(t_prio_level *level, t_input_level *input_level);

#endif