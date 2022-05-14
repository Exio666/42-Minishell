/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:14:16 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 21:15:50 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_an_asterix_out_of_quotes(t_lst_token *token)
{
	int	i;

	i = 0;
	if (token && token->type == TOK_WORD)
	{
		while (token->str[i])
		{
			if (is_wildcard(token->str[i]) && token->in_quotes[i] == FALSE)
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

int	end_of_both_str_reached(char *pattern, char * str)
{
	if (*pattern == '\0' && *str == '\0')
        return (TRUE);
	else
		return (FALSE);
}

int	characters_are_matching(char c1, char c2)
{
	if (c1 == c2)
		return (TRUE);
	else
		return (FALSE);
}

int	str_is_matching_pattern(char *pattern, char * str)
{
    if (end_of_both_str_reached(pattern, str))
        return TRUE;
    if (is_wildcard(*pattern) && *(pattern + 1) != '\0' && *str == '\0')
        return FALSE;
    if (characters_are_matching(*pattern, *str))
        return str_is_matching_pattern(pattern + 1, str + 1);
    if (is_wildcard(*pattern))
        return (str_is_matching_pattern(pattern + 1, str) || str_is_matching_pattern(pattern, str + 1));
    return FALSE;
}

/*
int main()
{
    test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	
	test7();
	test8();
	
	test9();
	test10();
	test11();
	
	test12();
    return 0;
}

void test0(void)
{
 	char pattern[] = "a";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test1(void)
{
 	char pattern[] = "a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test2(void)
{
 	char pattern[] = "*a";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test3(void)
{
 	char pattern[] = "*a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test4(void)
{
 	char pattern[] = "a*b";
    char str[] = "acb";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test5(void)
{
 	char pattern[] = "a*b*c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test6(void)
{
 	char pattern[] = "a*bc";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test7(void)
{
 	char pattern[] = "a*b*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test8(void)
{
 	char pattern[] = "a*b";
    char str[] = "ajbjc";

	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test9(void)
{
 	char pattern[] = "**c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test10(void)
{
 	char pattern[] = "*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test11(void)
{
 	char pattern[] = "a*c";
    char str[] = "ajbvrgregerhrehhrjc";
	printf("EXPECT MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test12(void)
{
 	char pattern[] = "a*b*cefewfew";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(str_is_matching_pattern(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
*/
