/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:02 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/19 21:11:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENISATION
# define TOKENISATION

# include "minishell.h"

char	**ft_split_pipe_seq(char *s, char *sep);
void	pipe_skipe_space(t_pipe_sequence_token *pipe_seq, int *index);

int		is_separator(char c, char *separator);
int		is_quote(char c);

char	*insert_token_separator(char *str, char *sep);
char	*insert_token_redirect_in(void);
char	*insert_token_redirect_out(void);
char	*insert_token_pipe(void);

#endif