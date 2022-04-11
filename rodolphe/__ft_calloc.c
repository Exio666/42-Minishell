/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:17:04 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/11 12:26:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*back;
}	t_dlist;

void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	*ft_calloc(size_t nmenb, size_t size);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	*__ft_calloc(ssize_t size);
t_list	*ft_lstnew(void *content);

int	main(void)
{
	char *str = __ft_calloc(10);
	str[1] = '2';
	char *test = __ft_calloc(20);
	__ft_calloc(-1);
	return (0);
}

void	*__ft_calloc(ssize_t size)
{
	static t_list	*list_malloc;
	t_list			*new;
	void			*content;

	if (size < 0)
	{
		ft_lstclear(&list_malloc);
		return (NULL);
	}
	content = ft_calloc(1, size);
	if (!content)
	{
		ft_lstclear(&list_malloc);
		return (NULL);
	}
	new = ft_lstnew(content);
	if (!new)
	{
		free(content);
		ft_lstclear(&list_malloc);
		return (NULL);
	}
	if (!list_malloc)
		list_malloc = new;
	else
		ft_lstadd_back(&list_malloc, new);
	return (content);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}


void	ft_lstdelone(t_list *lst)
{
	free(lst);
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

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	tmp->next = new;
}

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*array;

	array = malloc(size * nmenb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmenb);
	return (array);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (lst);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}