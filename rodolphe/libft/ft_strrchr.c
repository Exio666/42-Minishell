/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:39 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/30 10:23:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occur;

	last_occur = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last_occur = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		last_occur = (char *) &s[i];
	return (last_occur);
}
