/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:56:03 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/05 20:07:46 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	main(int argc, char **argv)
{
	t_logic_op		**logical_op;
	t_input_level	*input_level;

	input_level = attribute_level(argv[1]);
	logical_op = create_logical_op_array(argv[1]);
	logical_op_parser(logical_op, input_level);
	return (0);
}
