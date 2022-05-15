/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc_env.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:06:37 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:42:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_CALLOC_ENV_H
# define __FT_CALLOC_ENV_H

# include "minishell.h"

void	*__ft_calloc_env(ssize_t size);
char	*ft_itoa_env(int n);
char	*ft_strdup_env(const char *src);

#endif