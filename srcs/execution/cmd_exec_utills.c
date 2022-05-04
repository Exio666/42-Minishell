/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:53:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/04 14:43:29 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_lst_token *token, t_lst_env *env_list)
{
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			token = skip_two_token(token);
		if (!token)
			break ;
		if (token->type == TOK_WORD || token->type == TOK_DOUBLE_QUOTE)
		{
			if (token->str)
				token->str = expand_token(token->str, env_list);
		}
		token = token->next;
	}
}

void	tokenisation_post_expand(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
	{
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
