/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_founf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:00:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 20:33:46 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_NOT_FOUNF_H
# define CMD_NOT_FOUNF_H

# include "minishell.h"

int		ft_print_not_found(char *cmd, char **all_path, int i);
void	double_print_fd(char *str1, char *str2, int fd);

#endif