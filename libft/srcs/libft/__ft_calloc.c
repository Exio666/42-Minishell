/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:00:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/08 16:39:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*__ft_calloc(ssize_t size)
{
	static t_dlist	*list_malloc;
	t_dlist			*new;
	void			*content;

	if (size < 0)
	{
		ft_dlistclear(&list_malloc, &free);
		return (NULL);
	}
	content = ft_calloc(1, size);
	if (!content)
	{
		ft_dlistclear(&list_malloc, &free);
		return (NULL);
	}
	new = ft_dlistnew(content);
	if (!new)
	{
		free(content);
		ft_dlistclear(&list_malloc, &free);
		return (NULL);
	}
	if (!list_malloc)
		list_malloc = new;	
	ft_dlistadd_back(&list_malloc, new);
	return (content);
}
