/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_separator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:11 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_BY_SEPARATOR_H
# define SPLIT_BY_SEPARATOR_H

char	**split_by_separator(char *s, char *sep);
int		is_separator(char c, char *separator);

#endif
