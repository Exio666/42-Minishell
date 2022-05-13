/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:53:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/13 11:14:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_size_2d_array(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void	insert_split_in_token_list(t_lst_token *token, char **split)
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
				int size = ft_size_2d_array(split);
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

char	*dup_without_extra_space_quote(char *str)
{
	char	*dup;
	int		end;
	int		i;
	int		j;
	int		begun_with_quote = 0;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (is_quote(str[i]))
	{
		begun_with_quote = 1;
		i++;
	}
	end = ft_strlen(str) - 1;
	while (is_space(str[end]))
		end--;
	while (begun_with_quote && is_quote(str[end]))
		end--;
	dup = __ft_calloc(sizeof(char) * ((end - i) + 2));
	j = 0;
	while (str[i + j] && (i + j <= end))
	{
		dup[j] = str[i + j];
		j++;
	}
	return (dup);
}

void	tokenisation_post_expand(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
	{
		token->str = dup_without_extra_space(token->str);
		token = token->next;
	}
}

char	**create_argv_cmd(t_lst_token *token)
{
	char		**argv_cmd;
	int			nb_word_tok;
	int			i;
	t_lst_token	*copie;

	copie = token;
	nb_word_tok = count_tok_word(token);
	argv_cmd = __ft_calloc(sizeof(char *) * (nb_word_tok + 1));
	i = 0;
	while (i < nb_word_tok)
	{
		if (is_str_token(copie->type))
		{
			argv_cmd[i] = copie->str;
			i++;
		}
		else if (is_redirect_token(copie->type))
			copie = copie->next;
		if (copie)
			copie = copie->next;
	}
	argv_cmd[i] = NULL;
	return (argv_cmd);
}
