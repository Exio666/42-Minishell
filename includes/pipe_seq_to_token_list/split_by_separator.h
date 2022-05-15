/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_separator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:11 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:34:12 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_BY_SEPARATOR_H
# define SPLIT_BY_SEPARATOR_H

void	move_foward_split_by_separator(char *s, int *i);
char	**split_by_separator(char *s, char *sep);

#endif
