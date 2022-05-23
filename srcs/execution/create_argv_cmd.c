/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:58:32 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/23 08:53:37 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_str_in_array(t_lst_token	*copie, char **argv, int *i, int *j)
{
	if (copie->str[0] != '\0')
	{
		argv[(*i)] = copie->str;
		(*i)++;
	}
	(*j)++;
}

char	**create_argv_cmd(t_lst_token *token)
{
	char		**argv_cmd;
	int			nb_word_tok;
	int			i;
	int			j;
	t_lst_token	*copie;

	copie = token;
	nb_word_tok = count_tok_word(token);
	argv_cmd = __ft_calloc(sizeof(char *) * (nb_word_tok + 1));
	i = 0;
	j = 0;
	while (j < nb_word_tok)
	{
		if (is_str_token(copie->type))
			insert_str_in_array(copie, argv_cmd, &i, &j);
		else if (is_redirect_token(copie->type))
			copie = copie->next;
		if (copie)
			copie = copie->next;
	}
	argv_cmd[i] = NULL;
	return (argv_cmd);
}
