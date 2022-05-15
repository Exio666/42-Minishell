/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:17:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 12:47:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
static void	__ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
}

static void	__free_exit(t_list **lst, int do_exit)
{
	__ft_lstclear(lst);
<<<<<<< HEAD
	*lst = NULL;
=======
	if (do_exit == 1)
	{
		ft_putstr_fd("malloc failed\n", 2);
		exit(1);
	}
>>>>>>> bdafd4307ba570a8fc08738532e43b35c0526c24
}

void	*__ft_calloc(ssize_t size)
{
	static t_list	*list_malloc;
	t_list			*new;
	void			*content;

	if (size < 0)
	{
<<<<<<< HEAD
		printf("freing\n");
		__free_exit(&list_malloc);
=======
		__free_exit(&list_malloc, 0);
>>>>>>> bdafd4307ba570a8fc08738532e43b35c0526c24
		return (NULL);
	}
	content = ft_calloc(1, size);
	if (!content)
		__free_exit(&list_malloc, 1);
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		__free_exit(&list_malloc, 1);
	}
	if (!list_malloc)
		list_malloc = new;
	else
		ft_lstadd_back(&list_malloc, new);
	return (content);
}
