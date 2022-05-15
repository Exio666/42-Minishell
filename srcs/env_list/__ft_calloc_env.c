/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_calloc_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 10:59:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 11:29:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	__free_exit(t_list **lst)
{
	__ft_lstclear(lst);
}

void	*__ft_calloc_env(ssize_t size)
{
	static t_list	*list_malloc;
	t_list			*new;
	void			*content;

	if (size < 0)
	{
		__free_exit(&list_malloc);
		return (NULL);
	}
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

static int	len_number(long int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n < 10)
		return (1);
	if (n < 0 && n > -10)
		return (2);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static char	*ft_itoa_zero(char *nb)
{
	nb [0] = '0';
	nb [1] = '\0';
	return (nb);
}
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
