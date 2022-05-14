/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:50:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 14:08:06 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_FUNCTIONS_H
# define IS_FUNCTIONS_H

# include "minishell.h"

int	is_space(char c);
int	is_wildcard(char c);
int	is_separator(char c, char *separator);

#endif