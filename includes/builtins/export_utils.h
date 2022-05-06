/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:19:10 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/05 11:20:07 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_UTILS_H
# define EXPORT_UTILS_H

# include "minishell.h"

int	check_arg_export(char *arg);
int	ft_strlen_stop_car(char *str, char c);
int	str_conctent_car(char *str, char c);

#endif