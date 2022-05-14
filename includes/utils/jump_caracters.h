/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_caracters.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:16:50 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/14 19:14:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JUMP_CARACTERS_H
# define JUMP_CARACTERS_H

# include "minishell.h"

int		jump_caracters(char *str, char *caracters, int index, int step);
int		is_quote(char c);
int		is_simple_quote(char c);
int		is_double_quote(char c);
int		skip_quote(char *commande, int *i);

#endif