/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:50:05 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:26:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_FUNCTIONS_H
# define IS_FUNCTIONS_H

# include "minishell.h"

int	is_dollar(char c);
int	is_white_space(char c);
int	is_wildcard(char c);
int	is_separator(char c, char *separator);
int	is_dot(char c);

#endif