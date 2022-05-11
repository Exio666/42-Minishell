/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_heredoc.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:12:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/11 17:13:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_ALL_HEREDOC_H
# define CREATE_ALL_HEREDOC_H

#include "minishell.h"

void	create_all_heredoc(t_btree	**root, char *commande_line);
void	tab_of_pipe_sequense_token(t_btree *root, t_btree **tab, int *nb);
void	sort_tab_token(t_btree **tab, int size);

#endif