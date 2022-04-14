/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_sequence.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:12:29 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 15:40:46 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PIPE_SEQUENCE_H
# define GET_PIPE_SEQUENCE_H

# include "minishell.h"

char	*get_pipe_sequence(char	*user_input, int start_index);
int		get_size_pipe_sequence(int start_index, int end_index);

#endif