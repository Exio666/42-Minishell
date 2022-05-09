/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:34:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/09 16:28:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "minishell.h"

int			ft_unset(int ac, char **arg, t_lst_env **envp);
int			delete_varraible(char *name, t_lst_env **envp);
int			check_arg_unset(char *arg);
t_lst_env	*find_element_with_name(char *name, t_lst_env **envp);

#endif