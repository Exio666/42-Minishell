/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_logic_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:44:34 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 15:45:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    get_logic_op_from_end(char *user_input, int i)
{
    if (i != 0 && is_and_symbol(user_input[i])
        && is_and_symbol(user_input[i - 1]))
        return (AND_OPERATOR);
    else if (i != 0 && is_or_symbol(user_input[i])
        && is_or_symbol(user_input[i - 1]))
        return (OR_OPERATOR);
    else
        return (OPERATOR_NOT_FOUND);
}

int	get_logic_op_from_begin(char *user_input, int i)
{
	if (is_and_symbol(user_input[i])
		&& is_and_symbol(user_input[i + 1]))
		return (AND_OPERATOR);
	else if (is_or_symbol(user_input[i])
		&& is_or_symbol(user_input[i + 1]))
		return (OR_OPERATOR);
	else
		return (OPERATOR_NOT_FOUND);
}
