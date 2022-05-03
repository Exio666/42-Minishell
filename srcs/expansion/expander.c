/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:00:46 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/21 14:27:49 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//faut que on commence a avoir un executable minishell jpp de compiler tout a la main et de regarder quelle fichier il faut

//tester comment gere bash pour les varriable avec une fonction qui print les varraible nottament pour les varriable d'environement et les espaces car si c'est un prog externe a bash il peut quand meme etre excuter avvec son nom 

//regarder avec varriable non intialise je sais plus si c'est completer aveec un espace ou rien donc soit pour faire tout une string avec plusieur varriable on passe par NULL sinon pas le choix on doit passer par une structure qui auras la variable et une autre pour dire si c'est la fin

//test fonction avec une seul variable et a la fin comme si c'etait un token word

//ajouter checker pour le dollar car j'ai jamais checker les bug avec

//on peut faire un truc avec des /0 et en troncant le debut pour les " et en passant par une varriable temporraire
//juste chiant de trimer le nom de la variable sinon tout devrais marcher comme un simple expansion avec un boucle en plus mais passage par un structure obligatoire pour l'index 
//plus de probleme avec la fin mais quand meme obliger de savoir ce que fait une varriable non initialiser

//a part si on garde en memoire la place et que l'on envoie l'adress se qui tronc automatiquement et le /0 nou limite l'arriere

//faut aussi reflechir pour cette wildcard de merde et quand elle est executer car je sans de la merde avec l'expansion si elle est entre cote
//a moins que on la gere lors de la premiere tokenisation pour apres respliter les argument d'ailleur faut tester les argument aussi de sa

//faut ajouter readline au flag et creer un fichier pour que valgrind ignore ses leaks

//mais truc vont merder car faut des malloc mais flemme d'en mettre trop donc je verrais quand je pourrais exectuter

// varriable non initialliser c'est du NULL

// il y a une merde avec les quote genre e"cho"

//je ppense que n strjoin est le pluus proopice en mettant dans une structure si ill faut la join ou pas avec la precedente

// on peut creer une autre liste chaine pour l'environement et une autre pour les varriable type $$ et $?

typedef	struct s_expansion
{
	char	*retour;
	int		index_current;
	int		index_prev;
	int		*index_prev_prev;
	char	*env_varriable_name;
	char	*env_varriable_content;
}	
t_expansion;

char *len_varriable_in_str(char *src, int i)
{
	int	i;
	int	len;
	
	i++;
	len = 0;
	while (src[i] && ft_isalnum(src[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char *extract_varriable_name(char *src, t_expansion *expand)
{
	int		i;
	char	*name_varriable;
	int		len;

	i = 0;
	len = len_varriable_in_str(src, expand->index_current);
	name_varriable = __ft_calloc(sizeof(char) * (len + 1));
	expand->index_current++;
	while (src[expand->index_current] && ft_isalnum(src[expand->index_current]))
	{
		name_varriable[i] = src[expand->index_current];
		i++;
		expand->index_current++;
	}
	name_varriable[i] = /0;
	return (name_varriable);
}

void	init_struct_expansion(t_expansion *expand)
{
	expand->index_current = 0;
	expand->index_prev = 0;
	expand->index_prev_prev = 0;
	expand->env_varriable_name = NULL;
	expand->env_varriable_content = NULL;
	expand->retour = __ft_calloc(1);
	expand->retour[0] = '/0';
}

char *ft_expand(char *src)
{
	t_expansion	expand;

	init_struct_expansion(&expand);
	while (src[expand.index_current])
	{
		if (src[expand.index_current] == "$")
		{
			expand.index_prev = expand.index_current; 
			expand.env_varriable_name = extract_varriable_name(src, &expand);
			expand.env_varriable_content = get_variable_content(expand.env_varriable_name); // retourne $ si on lui \0
			src[expand->index_prev] = '\0';
			expand.index_prev_prev = expand.index_prev;
			expand.retour = ft_strjoin(expand.retour, &src[expand.index_prev_prev]);
			expand.retour = ft_strjoin(expand.retour, expand.env_varriable_content);
		}
		expand.index_current++;
	}
	return (ft_strjoin(expand.retour, &src[expand.index_prev_prev]));
}


