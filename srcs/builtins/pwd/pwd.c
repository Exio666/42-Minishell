/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:55:12 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/03 16:41:08 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = __ft_calloc(sizeof(char) * 2048);
	getcwd(str, 2048);
	if (!str)
		return (1);
	printf("%s\n", str);
	return (0);
}
