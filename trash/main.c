/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:18 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/25 09:43:10 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*commande;

	commande = "\'(test ())";
	if (primary_checker(commande) == TRUE)
		printf("The checker say 'commande is good'\n");
	else
		printf("The checker say 'commande is bad'\n");
}
