/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_funct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:43 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 19:52:49 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DEBUG_FUNCT_H
# define PRINT_DEBUG_FUNCT_H

/*----- print_debug_funct.c -----*/

void	print2DUtil(t_btree *root, int space);
void	print2D(t_btree *root);
void	printab_input_level(t_input_level	*input_level, int len);
void	level_by_level_printing(t_btree *root);

#endif