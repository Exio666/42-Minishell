/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:13:25 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/16 17:41:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "minishell.h"

int	add_varr_env(char *name, char *variable, t_lst_env **envp);
int	put_variable(char *arg, t_lst_env **envp);
int	ft_export(int ac, char **arg, t_lst_env **envp);

#endif
