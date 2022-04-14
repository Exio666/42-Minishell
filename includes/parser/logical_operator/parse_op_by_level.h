/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_by_level.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:21 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 14:32:46 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OP_BY_LEVEL_H
# define PARSE_OP_BY_LEVEL_H

# include "minishell.h"

/*----- parser_logical_op.c -----*/

t_btree	*parse_op_by_level(t_logic_op **logical_op,
			t_input_level *input_level);
int		priority_levels_remaining(int actual_level, int level_max);
int		actual_level_not_fully_checked(int i);
int		is_part_of_current_level(int char_level, int actual_level);
int		logical_op_type_is_found(int logical_op_type);

#endif