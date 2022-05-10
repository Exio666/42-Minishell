/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:26:33 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 08:28:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_QUOTES_H
# define REMOVE_QUOTES_H

# include "minishell.h"

int		set_space_to_split(int space_to_split);
char	*remove_quotes(t_lst_token *token, t_lst_quote *lst_quote);

#endif