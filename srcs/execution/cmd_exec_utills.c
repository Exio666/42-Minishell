/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_utills.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:53:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/15 13:10:25 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_size_2d_array(char **array)
{
    int    size;

    size = 0;
    while (array[size])
        size++;
    return (size);
}

void    insert_split_in_token_list(t_lst_token *token, t_split *split)
{
    t_lst_token    *new;
    t_lst_token    *tmp;
    int            i;

    if (split->size_2d_array <= 1)
        return ;
    token->str = split->split[0];
    i = 1;
    while (split->split[i])
    {
        tmp = token->next;
        new = create_token_for_split(split->split[i], split->in_quotes[i]);
        token->next = new;
        new->next = tmp;
        token = token->next;
        i++;
    }    
}

int    skip_quote_exc(char *str, int *index)
{
    int        begun_with_quote;

    begun_with_quote = 0;
    while (is_quote(str[*index]))
    {
        begun_with_quote = 1;
        (*index)++;
    }
    return (begun_with_quote);
}

char    *dup_without_extra_space_quote(char *str)
{
    char    *dup;
    int        end;
    int        i;
    int        j;
    int        begun_with_quote;

    i = 0;
    while (is_white_space(str[i]))
        i++;
    begun_with_quote = skip_quote_exc(str, &i);
    end = ft_strlen(str) - 1;
    while (is_white_space(str[end]))
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
/*
void    tokenisation_post_expand(t_lst_token *token)
{
    while (token && token->type != TOK_PIPE)
    {
        token->str = dup_without_extra_space(token->str);
        token = token->next;
    }
}
*/
