/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:36:17 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 09:51:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

char	*ft_strjoin(char const *s1, char const *s2);
int	is_wildcard(char c);
void save(char *new_token, struct dirent *entity, int i, int i_bis, int j);

char	*match_pattern(char *pattern, char *str)
{
	
}

int	main(int argc, char *argv[])
{
	int i, j, i_bis;
	(void)(argc);

	char pattern[] = "*dc*";
	char *new_token = NULL;
	DIR *dir = opendir(".");

	
	if (dir == NULL)
		return (1);	
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (match_pattern(pattern, entity->d_name))
		{
			ft_strjoin(new_token, entity->d_name);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (0);
}


/*
int	main(int argc, char *argv[])
{
	int i, j, i_bis;
	(void)(argc);
	struct dirent	*entity;
	char token[] = "*dc*";
	char *new_token = NULL;
	DIR *dir = opendir(".");

	
	if (dir == NULL)
		return (1);	
	entity = readdir(dir);
	while (entity != NULL)
	{
//		printf("%s\n", entity->d_name);
		i = 0;
		j = 0;
		while (token[i])
		{
			j = 0;
			if (is_wildcard(token[i]))
			{
				skip_wildcard(token, &i);
				if (token[i])
				{
					i_bis = i;
//					j = 0;
					while (entity->d_name[j])
					{
						//tant que token[i_bis] et entite[j] ne sont pas égale on avance
						while (entity->d_name[j] && (entity->d_name[j] != token[i_bis]))
							j++;
						if (entity->d_name[j])
						{
							//on avance tant que token et l entité sont égal et tant qu on ne rencontre pas de wildcard dans token
							while (token[i_bis] && entity->d_name[j] && entity->d_name[j] == token[i_bis] && !is_wildcard(token[i_bis]))
							{
								i_bis++;
								j++;
							}
							//si on est a la fin du token et que l entité n'est pas terminé on sort de la boucle entity
							if (!token[i_bis] && entity->d_name[j])
							{
							// sinon si les deux caracteres différe et qu on a pas rencontre de wildcar, on remet les compteurs à zero
							// pour token et on va continuer a parcourir l entité
								i = i_bis;
							}
							else if (token[i_bis] && entity->d_name[j] && entity->d_name[j] =! token[i_bis] && !is_wildcard(token[i_bis]))
							{
								break ;
							}
							//sinon si l 'entité existe et qu on a rencontre une wildcard
							else if (entity->d_name[j] && is_wildcard(token[i_bis]))
							{
								skip_wildcard(token, &i_bis);
								//si on a une wildcard en fin de token on sauvegarde
								if (token[i_bis] == '\0')
								{
									save();
									i = i_bis;
									break ;
								}
							}
						}
//						j++;
					}
						
				}
				else
					save();
			}
//		i++;
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (0);
}
*/
void save(char *new_token, struct dirent *entity, int i, int i_bis, int j)
{
	new_token = ft_strjoin(new_token, entity->d_name);
	ft_strjoin(new_token, " ");
	i = i_bis + 1;
	j++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = calloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
int	is_wildcard(char c)
{
	if (c == '*')
		return (1);
	else
		return (0);
}

/*_____________________________________*/

