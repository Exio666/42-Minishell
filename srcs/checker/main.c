/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:18 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/25 08:34:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	char *commande;

	commande = "\'(test ())";
	if(primary_checker(commande) == TRUE)
		printf("The checker say 'commande is good'\n");
	else
		printf("The checker say 'commande is bad'\n");
}