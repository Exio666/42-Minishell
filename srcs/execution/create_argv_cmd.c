/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:58:32 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/14 19:07:57 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
