/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:15:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/13 15:40:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int	is_wildcard(char c)
{
	
	if (c == '*')
		return (true);
	else
		return (false);
}
*/
int end_of_both_str_reached(char *pattern, char * str)
{
	if (*pattern == '\0' && *str == '\0')
        return (true);
	else
		return (false);
}

int characters_are_matching(char c1, char c2)
{
	if (c1 == c2)
		return (true);
	else
		return (false);
}

int is_matching(char *pattern, char * str)
{
    if (end_of_both_str_reached(pattern, str))
        return true;
    if (is_wildcard(*pattern) && *(pattern + 1) != '\0' && *str == '\0')
        return false;
    if (characters_are_matching(*pattern, *str))
        return is_matching(pattern + 1, str + 1);
    if (is_wildcard(*pattern))
        return (is_matching(pattern + 1, str) || is_matching(pattern, str + 1));
    return false;
}


char	*expand_wildcard(char **token, int *i, t_lst_env *env_list)
{
	char	*wildcard_content;
	int		wildcard_content_len;

	wildcard_content = NULL;
	wildcard_content_len = 0;
	wildcard_content = get_wildcard_content();
	if (!wildcard_content)
	{
		wildcard_content = __ft_calloc(sizeof(char) * 1);
		wildcard_content_len = 0;
	}
	else
		wildcard_content_len = ft_strlen(wildcard_content);
	insert_var_content_to_token(&token, wildcard_content, *index);
	*index = *index + (wildcard_content_len - 1);
	return (token);
}

/* il n'y  a pas d'expand de wildcard entre quote, mais il falloir mettre a jour la position des quotes à remove, car l'expansion 
de la wildcard pourrait les déplacés. (position quote = position quote + wildcard expanded len?)
*/

t_lst_token	*expand_all_wildcards(t_lst_token *token, t_lst_env *env_list)
{
	int				i;

	i = 0;
	while (token && token->str[i])
	{
		if (is_wildcard(token->str[i]) && !token->in_quotes[i])
			expand_wildcard(&token, &i, env_list);
		i++;
	}
	return (token);
}


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
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test1(void)
{
 	char pattern[] = "a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test2(void)
{
 	char pattern[] = "*a";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test3(void)
{
 	char pattern[] = "*a*";
    char str[] = "a";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test4(void)
{
 	char pattern[] = "a*b";
    char str[] = "acb";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test5(void)
{
 	char pattern[] = "a*b*c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test6(void)
{
 	char pattern[] = "a*bc";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test7(void)
{
 	char pattern[] = "a*b*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test8(void)
{
 	char pattern[] = "a*b";
    char str[] = "ajbjc";

	printf("EXPECT NO MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}
void test9(void)
{
 	char pattern[] = "**c";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test10(void)
{
 	char pattern[] = "*";
    char str[] = "ajbjc";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test11(void)
{
 	char pattern[] = "a*c";
    char str[] = "ajbvrgregerhrehhrjc";
	printf("EXPECT MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

void test12(void)
{
 	char pattern[] = "a*b*cefewfew";
    char str[] = "ajbjc";
	printf("EXPECT NO MATCH\n");
    if(is_matching(pattern, str))
		printf("match\n");
    else	
		printf("no match\n");	
}

/*
// Function that matches an input string with a given wildcard pattern
bool isMatch(char *word, char *pattern, int word_len, int pattern_len, int **look_up)
{

	
	if (pattern_len < 0 && word_len < 0)	// If both the input string and pattern reach their end, return true
	{

		return true;
	}
	else if (pattern_len < 0) // If only the pattern reaches its end, return false
		return false;
	else if (word_len < 0)	// If only the input string reaches its end, return true if the remaining characters in the pattern are all '*'
	{
		for (int i = 0; i <= pattern_len; i++)
		{
			if (pattern[i] != '*') {
				return false;
			}
		}

		return true;
	}

	// If the subproblem is encountered for the first time
	if (!look_up[pattern_len][word_len])
	{
		if (pattern[pattern_len] == '*')
		{
			// 1. '*' matches with current characters in the input string.
			// Here, we will move to the next character in the string.

			// 2. Ignore '*' and move to the next character in the pattern
			if (isMatch(word, pattern, word_len - 1, pattern_len, look_up) || isMatch(word, pattern, word_len, pattern_len - 1, look_up))
			look_up[pattern_len][word_len] = 1;
		}
		else
		{
			// If the current character is not a wildcard character, it
			// should match the current character in the input string
			if (pattern[pattern_len] != word[word_len])
				look_up[pattern_len][word_len] = 0;
			// check if pattern[0…m-1] matches word[0…n-1]
			else
				look_up[pattern_len][word_len] = isMatch(word, pattern, word_len - 1, pattern_len - 1, look_up);
		}
	}
	return look_up[pattern_len][word_len];
}

// Wildcard Pattern Matching Implementation in C++
int main()
{
	char	*word = "xy";
	char	*pattern = "xyx";

	int word_len = strlen(word);
	int pattern_len = strlen(pattern);
	int **look_up = calloc(word_len + 1,  sizeof(int*));
	for (int i = 0; i < word_len; i++)
		look_up[i] = calloc(pattern_len + 1, sizeof(int));
	
	look_up[0][0] = true;
	if (isMatch(word, pattern, word_len - 1, pattern_len - 1, look_up)) {
		printf("Match\n");
	}
	else {
		printf("No Match\n");
	}
	return 0;
}
*/