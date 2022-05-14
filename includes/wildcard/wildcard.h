/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:47:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 19:51:26 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_H
# define WILDCARD_H

# include "minishell.h"

void	expand_wildcard_command(t_lst_token *token);
void	insert_new_token_list(t_lst_token *new_token_list,
	t_lst_token *current_token);
int	ft_size_token_list(t_lst_token *token);
int both_start_with_dot(char *pattern, char *str);
t_lst_token	*expand_wildcard_token(t_lst_token *token);
int	is_an_asterix_out_of_quotes(t_lst_token *token);
int	end_of_both_str_reached(char *pattern, char * str);
int	characters_are_matching(char c1, char c2);
int	str_is_matching_pattern(char *pattern, char * str);
/*
void test0(void);
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);
*/
#endif