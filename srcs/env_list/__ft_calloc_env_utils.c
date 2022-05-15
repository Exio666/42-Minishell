/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc_env_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:21:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 21:23:09 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_itoa_env(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = (long int)n;
	i = len_number(nb) - 1;
	str = __ft_calloc_env(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_itoa_zero(str));
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}

char	*ft_strdup_env(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = NULL;
	if (src)
		dest = __ft_calloc_env(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
