/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:54 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 15:39:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*array;

	array = __ft_calloc(size * nmenb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmenb);
	return (array);
}
