/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:07:02 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:13:55 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENISATION
# define TOKENISATION

# include "minishell.h"


char	**split_by_separator(char *s, char *sep);
t_token	*create_token(char	*space_split);
t_list	*create_token_list(char **split);
char**ft_split_pipe_by_space(char *s, char *sep);


int	find_token_type(char *str);
int	is_redirect_in_token(char *str);
int	is_redirect_out_token(char *str);
int	is_redirect_out_append_token(char *str);
int	is_pipe_token(char *str);
int	is_dollar_token(char *str);
int	is_single_quote_token(char *str);
int	is_double_quote_token(char *str);
int	is_here_doc_token(char *str);

void	add_token_to_lst(t_list **lst, t_token *token);

char	*dup_without_extra_space(char *str);


char *insert_token_separator(char *str, char *sep);
char *insert_token_heredoc(void);
char *insert_token_redirect_in(void);
char *insert_token_redirect_out_append(void);
char *insert_token_redirect_out(void);
char *insert_token_pipe(void);


int	is_separator(char c, char *separator);

void print_split_tab(char **split);
void print_split_lst(t_list	*lst);
#endif