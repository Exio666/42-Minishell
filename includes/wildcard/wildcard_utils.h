/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:13:15 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 21:26:58 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_UTILS_H
# define WILDCARD_UTILS_H

# include "minishell.h"

int	is_an_asterix_out_of_quotes(t_lst_token *token);
int	end_of_both_str_reached(char *pattern, char *str);
int	characters_are_matching(char c1, char c2);
int	str_is_matching_pattern(char *pattern, char *str);

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