/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:16:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/04 14:29:27 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_BUILTINS_H
# define EXEC_BUILTINS_H

# include "minishell.h"

int	exec_builtins(int ac, char **av, t_lst_env **envp);

#endif