/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:53:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 13:47:31 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int size_2d_array(char **array)
{
	int size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void insert_split_in_token_list(t_lst_token *token, char **split)
{
	t_lst_token	*new;
	t_lst_token	*tmp;
	int			i;

	token->str = split[0];
	i = 1;
	while (split[i])
	{
		tmp = token->next;
		new = create_token(split[i]);
		token->next = new;
		new->next = tmp;
		token = token->next;
		i++;
	}	
}

/*
//			printf("TEMOIN 0\n");
			if (token->type == TOK_WORD)
			{
				char **split = split_pipe_by_space(token->str);
				int size = size_2d_array(split);
//				printf("TEMOIN 1\n");
				if (size > 1)
				{
					insert_split_in_token_list(token, split);
				}
//				printf("TEMOIN 2\n");
				int i = 0;
				while (token && i < size - 1)
				{
					i++;
					token = token->next;
				}
//				printf("TEMOIN 3\n");
			}
			//END ADD
*/

void	expand(t_lst_token *token, t_lst_env *env_list)
{
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (!token)
			break ;
		if (token->str)
				token->str = expand_token(token->str, env_list);
		if (token)
			token = token->next;
	}
//c	printf("TEMOIN 4\n");
}

void	tokenisation_post_expand(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
	{
		if (token->type == TOK_WORD)
		{
			token->str = dup_without_extra_space(token->str);
			token->type = TOK_WORD;
		}
		if (token->type == TOK_SINGLE_QUOTE || token->type == TOK_DOUBLE_QUOTE)
			token->type = TOK_WORD;
			
		token = token->next;
	}
}

char	**create_argv_cmd(t_lst_token *token)
{
	char		**argv_cmd;
	int			nb_word_tok;
	int			i;
	t_lst_token	*first_token_of_cmd;

	first_token_of_cmd = find_first_token_cmd(token);
	nb_word_tok = count_tok_word(token);
	argv_cmd = __ft_calloc(sizeof(char *) * (nb_word_tok + 1));
	i = 0;
	while (i < nb_word_tok)
	{
		argv_cmd[i] = token->str;
		token = token->next;
		i++;
	}
	return (argv_cmd);
}
