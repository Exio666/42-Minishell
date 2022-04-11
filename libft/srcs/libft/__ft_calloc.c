/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:17:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 15:32:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__ft_lstclear(t_list **lst);
void	__free_exit(t_list **lst);

void	*__ft_calloc(ssize_t size)
{
	static t_list	*list_malloc;
	t_list			*new;
	void			*content;

	if (size < 0)
		__free_exit(&list_malloc);
	content = ft_calloc(1, size);
	if (!content)
		__free_exit(&list_malloc);
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		__free_exit(&list_malloc);
	}
	if (!list_malloc)
		list_malloc = new;
	else
		ft_lstadd_back(&list_malloc, new);
	return (content);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}

void	__free_exit(t_list **lst)
{
	ft_lstclear(lst);
	return (NULL);
}
