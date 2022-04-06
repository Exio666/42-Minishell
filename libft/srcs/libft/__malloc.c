/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:00:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/06 15:46:35 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*__malloc(ssize_t size)
{
	static t_dlist	**list_malloc;
	t_dlist			*new;
	void			*content;

	if (size < 0)
	{
		ft_dlistclear(list_malloc, &free);
		return (NULL);
	}
	content = ft_calloc(1, size);
	if (!content)
	{
		ft_dlistclear(list_malloc, &free);
		return (NULL);
	}
	new = ft_dlistnew(content);
	if (!new)
	{
		free(content);
		ft_dlistclear(list_malloc, &free);
		return (NULL);
	}
	ft_dlistadd_back(list_malloc, new);
	return (content);
}

void	*__malloc(size_t size)
{
	static t_dlist	**list_malloc;
	t_dlist			*new;
	void			*content;

	content = malloc(size);
	if (!content)
	{
		ft_dlistclear(list_malloc, &free);
		return (NULL);
	}
	new = ft_dlistnew(content);
	if (!new)
	{
		free(content);
		ft_dlistclear(list_malloc, &free);
		return (NULL);
	}
	ft_dlistadd_back(list_malloc, new);
	return (content);
}
