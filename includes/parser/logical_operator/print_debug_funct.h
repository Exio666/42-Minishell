/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_funct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/28 14:16:44 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DEBUG_FUNCT_H
# define PRINT_DEBUG_FUNCT_H

# include "minishell.h"

/*----- print_debug_funct.c -----*/

void	print2DUtil(t_btree *root, int space);
void	print2D(t_btree *root);
void	printab_input_level(t_input_level	*input_level);
void	level_by_level_printing(t_btree *root);

#endif