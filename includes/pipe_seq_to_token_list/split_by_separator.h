/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_separator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:11 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:56:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_BY_SEPARATOR_H
# define SPLIT_BY_SEPARATOR_H

char	**split_by_separator(char *s, char *sep);
int		is_separator(char c, char *separator);

# endif