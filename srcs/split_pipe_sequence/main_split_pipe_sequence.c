/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:08:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/20 22:13:03 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "echo a && echo b '|| (echo c || echo d)' && echo e"

# include "minishell.h"

typedef struct s_lst_leaf_node
{
	struct s_lst_leaf_node	*next;
	void					*content;
} t_lst_leaf_node;

typedef struct s_token
{
	char			*str;
	t_type_token	type;
}	t_token;

void	add_token_to_lst(t_list **lst, t_token *token)
{
	t_list	*elem;
	
	elem = ft_lstnew(token);
	ft_lstadd_back(lst, elem);	
}

int	is_redirect_in_token(char *str)
{
	if (*str == '<')
		return (TRUE);
	return (FALSE);
}

int	is_redirect_out_token(char *str)
{
	if (*str == '>')
		return (TRUE);
	return (FALSE);
}

int	is_redirect_out_append_token(char *str)
{
	if (*str == '>' && (*str + 1) == '>')
		return (TRUE);
	return (FALSE);
}

int	is_pipe_token(char *str)
{
	if (*str == '|')
		return (TRUE);
	return (FALSE);
}

int	is_dollar_token(char *str)
{
	if (*str == '$')
		return (TRUE);
	return (FALSE);
}

int	is_single_quote_token(char *str)
{
	if (*str == '\'')
		return (TRUE);
	return (FALSE);
}

int	is_double_quote_token(char *str)
{
	if (*str == '\"')
		return (TRUE);
	return (FALSE);
}

int	is_here_doc_token(char *str)
{
	if (*str == '<' && (*str + 1) == '<')
		return (TRUE);
	return (FALSE);
}

int	find_token_type(char *str)
{
	if (is_here_doc_token(str))
		return (TOK_HEREDOC);
	else if (is_redirect_in_token(str))
		return (TOK_REDIRECT_IN);
	else if (is_redirect_out_append_token(str))
		return (TOK_REDIRECT_OUT_APPEND);
	else if (is_redirect_out_token(str))
		return (TOK_REDIRECT_OUT);
	else if (is_pipe_token(str))
		return (TOK_PIPE);
	else if (is_single_quote_token(str))
		return (TOK_SINGLE_QUOTE);
	else if (is_double_quote_token(str))
		return (TOK_DOUBLE_QUOTE);
	else
		return (TOK_WORD);
}

char	*dup_without_extra_space(char *str)
{
	char *dup;
	int	len;
	int end;
	int i;
	int j;
	
	i = 0;
	while (is_space(str[i]))
		i++;
	len = ft_strlen(&str[i]);
	end = len - 1;
	while (is_space(str[end]))
		end--;
	dup = __ft_calloc(sizeof(char) * ((end - i) +2));
	j = 0;
	while (str[i + j] && (i + j <= end))
	{
		dup[j] = str[i + j];
		j++;
	}
	return (dup);
}

t_list	*tokenise_split_pipe_seq(char **split)
{
	int		i;
	int		j;
	char	**space_split;
	t_list	*lst;
	t_token	*token;

	lst = NULL;
	i = 0;
	while (split[i])
	{
		space_split = ft_split_pipe_by_space(split[i], " ");
		j = 0;
		while (space_split[j])
		{
			token = __ft_calloc(sizeof(t_token));
			token->str = dup_without_extra_space(space_split[j]);
			token->type = find_token_type(space_split[j]);
			add_token_to_lst(&lst, token);
			j++;
		}
		i++;
	}
	return (lst);
}

void print_split_tab(char **split)
{
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	printf("--------------------------\n");
}

void print_split_lst(t_list	*lst)
{
	while (lst)
	{
		t_token *ptr = lst->content;
	//	printf("%-10s - type token ==  %d\n", (char *)ptr->str, ptr->type);
		printf("%s\n", (char *)ptr->str);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	char **split;
	t_list	*lst;

	if (argc < 2)
	{
		printf("NEED_ARG\n");
		return (1);
	}
	
	printf("%s\n\n", argv[1]);
	
	split = ft_split_pipe_seq(argv[1], "|<>");
	print_split_tab(split);
	
	lst = tokenise_split_pipe_seq(split);
		print_split_lst(lst);

	__ft_calloc(-1);
	return (0);
}