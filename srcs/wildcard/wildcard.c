/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:36:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/12 16:20:55 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int	is_wildcard(char c)
{
	if (c == '*')
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	(void)(argc);
	struct dirent	*entity;
	char token[] = "*dc*";
	DIR *dir = opendir(".");
	if (dir == NULL)
		return (1);	
	entity = readdir(dir);
	while (entity != NULL)
	{
		printf("%s\n", entity->d_name);
		int i = 0;
		int i_bis = 0;
		int j = 0;
		while (token[i])
		{
			if (is_wildcard(token[i]))
			{
				while (is_wildcard(token[i]))
					i++;
				if (token[i])
				{
					i_bis = i;
					j = 0;
					while (entity->d_name[j])
					{
						while (entity->d_name[j] && (entity->d_name[j] != token[i_bis]))
							j++;
						if ((entity->d_name[j])
						{
							while (entity->d_name[j] != token[i_bis])
							{}
						}
							
					}
			}
				}
			i++;
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (0);
}