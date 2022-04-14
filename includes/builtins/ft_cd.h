/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:34:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/14 10:41:56 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include "minishell.h"

int	ft_cd_absolu_path(char *path_move);
int	no_dir(char *path_move);
int	ft_cd_relative_path(char *path_move);
int	ft_cd_movedir(char *path_move);
int	ft_cd(int ac, char *argv, t_lst_env **envp);

#endif