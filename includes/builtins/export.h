/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:13:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/05 11:19:54 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "minishell.h"

int	add_varr_env(char *name, char *varraible, t_lst_env **envp);
int	put_varraible(char *arg, t_lst_env **envp);
int	ft_export(int ac, char **arg, t_lst_env **envp);

#endif
