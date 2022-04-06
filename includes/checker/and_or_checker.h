/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:07:00 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/06 15:28:25 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AND_OR_CHECKER_H
# define AND_OR_CHECKER_H

# include "minishell.h"

void	and_checker(char *commande, t_checker *check);
void	or_checker(char *commande, t_checker *check);
int		and_or_pipe_checker(char *commande, t_checker *check);

#endif