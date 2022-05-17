/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:12:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 10:57:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGICAL_OPERATOR_H
# define LOGICAL_OPERATOR_H

# include "minishell.h"

# define COUNT 10
# define OPERATOR_NOT_FOUND 0
# define AND_OPERATOR 1
# define OR_OPERATOR 2

# define FALSE 0
# define TRUE 1
# define UI unsigned int

# include "btree_management.h"
# include "count_and_update_logic_op.h"
# include "find_specific_char_funct.h"
# include "get_logical_op.h"
# include "input_priority_level.h"
# include "increase_and_decrease_level.h"
# include "lstdelone_parser.h"
# include "logical_operator_indexation.h"
# include "parse_op_by_level.h"
# include "get_btree_of_logical_op.h"

#endif