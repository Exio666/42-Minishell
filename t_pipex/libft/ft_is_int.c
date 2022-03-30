/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/03/02 16:04:23 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	skip_zero(char *str, int i, int len)
{
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		ft_memcpy(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
		str[len - 1] = 0;
		len--;
	}
}

int	ft_is_int(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	len = ft_strlen(str);
	skip_zero(str, i, len);
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return (0);
	if (ft_strlen(str) < 10)
		return (1);
	if (ft_strlen(str) > 11)
		return (0);
	if (ft_strlen(str) == 10)
		if (ft_strncmp("2147483647", str, 10) < 0)
			return (0);
	if (ft_strlen(str) == 11)
		if (ft_strncmp("-2147483648", str, 11) < 0)
			return (0);
	return (1);
}
