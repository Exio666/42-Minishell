/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:35:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 20:00:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "minishell.h"

int		good_arg_for_exit(char *arg);
void	builtins_exit_prog(int ac, char **av);
int		ft_exit(int ac, char **av);

#endif