/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:40:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 14:41:18 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_FD_H
# define SAVE_FD_H

# include "minishell.h"

void	exit_save_fd(int cin, int cout);
void	multi_dup2(int cin, int cout);
void	save_fd(int mod);

#endif