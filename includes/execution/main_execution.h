/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:03:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 08:36:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_EXECUTION_H
# define MAIN_EXECUTION_H

# include "minishell.h"

void	exit_ctr_d(char *command_line);
void	process_command(char *command_line, t_lst_env *env_list);
char	*get_command_line(const char *prompt);

#endif