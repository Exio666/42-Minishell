/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:15:56 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 13:21:17 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <minishell.h>


void	expand_wildcard_command(t_lst_token *token)
{
	t_lst_token *new_token_list;
	int size_new_token_list;

	new_token_list = NULL;
	size_new_token_list = 0;
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (is_an_asterix_out_of_quotes(token))
		{
/*			printf("-----------------------------------\n");
			printf("token->str = [%s]\n", token->str);
			printf("token->type = [%d]\n", token->type);	*/
			new_token_list = expand_wildcard_token(token);
			if (new_token_list)
			{
				size_new_token_list = ft_size_token_list(new_token_list);
				insert_new_token_list(new_token_list, token);
				token = move_to_last_new_token(token, size_new_token_list);
				new_token_list = NULL;
			}
		/*	print_token_list(new_token_list);
			printf("-----------------------------------\n");	*/
		}
		if (token)
			token = token->next;
	}
}
void	insert_new_token_list(t_lst_token *new_token_list, t_lst_token *current_token)
{
	t_lst_token	*tmp;

	current_token->str = new_token_list->str;
	current_token->in_quotes = new_token_list->in_quotes;

	tmp = current_token->next;
	current_token->next = new_token_list->next;
	while (current_token->next)
		current_token = current_token->next;
	current_token->next = tmp;
}
int	ft_size_token_list(t_lst_token *token)
{
	int count;

	count = 0;
	if (!token)
		return (count);
	while (token)
	{
		count++;
		token = token->next;
	}
	return (count);
}
t_lst_token *expand_wildcard_token(t_lst_token *token)
{

	t_lst_token *token_list;
	t_lst_token *new_token;
	DIR	*dir;

	new_token = NULL;
	token_list = NULL;
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	struct dirent 	*entity;
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (entity->d_name[0] != '.' || (entity->d_name[0] == '.' && token->str[0] == '.'))
		{
			if (str_is_matching_pattern(token->str, entity->d_name))
			{
				new_token = create_token(entity->d_name);
			}
			if (new_token)
			{
				ft_lstadd_back_token(&token_list, new_token);
				new_token = NULL;
			}
		}
		entity = readdir(dir);
	}
	return (token_list);
}

int is_an_asterix_out_of_quotes(t_lst_token *token)
{
	int	i;

	i = 0;
	if (token && token->type == TOK_WORD)
	{
		while (token->str[i])
		{
			if (is_wildcard(token->str[i]) && token->in_quotes[i] == false)
				return (true);
			i++;
		}
	}
	return (false);
}


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

int str_is_matching_pattern(char *pattern, char * str)
{
    if (end_of_both_str_reached(pattern, str))
        return true;
    if (is_wildcard(*pattern) && *(pattern + 1) != '\0' && *str == '\0')
        return false;
    if (characters_are_matching(*pattern, *str))
        return str_is_matching_pattern(pattern + 1, str + 1);
    if (is_wildcard(*pattern))
        return (str_is_matching_pattern(pattern + 1, str) || str_is_matching_pattern(pattern, str + 1));
    return false;
}

/*
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
*/
/* il n'y  a pas d'expand de wildcard entre quote, mais il falloir mettre a jour la position des quotes à remove, car l'expansion 
de la wildcard pourrait les déplacés. (position quote = position quote + wildcard expanded len?)
*/
/*
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
*/
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
