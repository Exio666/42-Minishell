/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_heredoc.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:41:59 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 08:31:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCT_HEREDOC_H
# define DESTRUCT_HEREDOC_H

# include "minishell.h"

void	destuct_heredoc(t_btree	**tab, int nb_heredoc);
void	ctrl_d_heredoc(char *end, int line);

#endif