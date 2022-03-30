/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:54 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/24 17:36:03 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*array;

	array = malloc(size * nmenb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmenb);
	return (array);
}
