/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:45:37 by bsavinel          #+#    #+#             */
/*   Updated: 2022/04/04 16:25:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "minishell.h"

# ifndef DEBUG
#  define DEBUG 1
# endif

# define S_ERROR_M_QUOTE "Syntax error : missing \'\'\'"
# define S_ERROR_M_DQUOTE "Syntax error : missing \'\"\'"
# define S_ERROR_M_OPEN_PAR "Syntax error : missing ')'"
# define S_ERROR_NP_CLOSE_PAR "Syntax error : no pattern for ')'"

#endif