/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:07:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/12 15:07:35 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_CHECKER_H
# define QUOTE_CHECKER_H

# include "minishell.h"

int	quote_jump(char *commande, t_checker *check);
int	quote_parenthise_checker(char *commande, t_checker *check);

#endif