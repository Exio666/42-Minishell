/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 17:17:51 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_tree(t_btree *root, t_lst_env *env_list)
{
	if (!root)
		return ;
	execute_command_tree(root->left, env_list);
	if (root->token)
		execute_pipe_sequence(root->token, env_list);
	execute_command_tree(root->right, env_list);
}

// parcourir les commandes séparés par les pipes
void	execute_pipe_sequence(t_lst_token *token, t_lst_env *env_list)
{
	while (token)
	{
		execute_command(token, env_list);
		token = find_next_cmd(token);
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

void	execute_command(t_lst_token *token, t_lst_env *env_list)
{
	char	**argv;

	expand(token, env_list);
	tokenisation_post_expand(token);
	argv = find_cmd(token);
	if (argv)
	{	
		printf("-----------------\n");
		printf("argv_arg:\n");
		print_char_two_dim_array(argv);
		printf("-----------------\n");
	}
//	set_up_redirect_in();
//	set_up_redirect_out();
//	set_up_redirect_out_append();
//	execute();
}

char	**find_cmd(t_lst_token *token)
{
	char	**argv_cmd;

	argv_cmd = NULL;
	while (token && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type) || is_redirect_token(token->type))
			token = skip_two_token(token);
		if (token && token->type == TOK_WORD)
		{
			argv_cmd = create_argv_cmd(token);
			break ;
		}
		if (token)
			token = token->next;
	}
	return (argv_cmd);
}

char	**create_argv_cmd(t_lst_token *token)
{
	char	**argv_cmd;
	t_lst_token	*tmp;
	int		count_word_tok;
	int		i;
	
	tmp = token;
	count_word_tok = 0;
	while (tmp && tmp->type == TOK_WORD)
	{
		count_word_tok++;
		tmp = tmp->next;
	}
	argv_cmd = __ft_calloc(sizeof(char*) * (count_word_tok + 1));
	i = 0;
	tmp = token;
	
	while (i < count_word_tok)
	{
		argv_cmd[i] = tmp->str;
		tmp = tmp->next;
		i++;
	}
	print_char_two_dim_array(argv_cmd);
	return (argv_cmd);
}

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
				token->str = expand_command(token->str, env_list);
		}
		token = token->next;
	}
}

t_lst_token	*find_next_cmd(t_lst_token *token)
{
	while (token && token->type != TOK_PIPE)
		token = token->next;
	if (!token)
		return (NULL); //no more command
	else
		return (token->next); //considérant que le checker ne laisse pas passer une cmd qui se termine pas un |
}


int	is_redirect_token(t_type_token token_type)
{
	if (token_type == TOK_REDIRECT_IN)
		return (TRUE);
	else if (token_type == TOK_REDIRECT_OUT)
		return (TRUE);
	else if (token_type == TOK_REDIRECT_OUT_APPEND)
		return (TRUE);
	else
		return (FALSE);
}

int	is_heredoc_token(t_type_token token_type)
{
	if (token_type == TOK_HEREDOC)
		return (TRUE);
	else
		return (FALSE);
}

t_lst_token	*skip_two_token(t_lst_token *token)
{
	token = token->next;
	token = token->next;
	return (token);
}




#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

//int	main(int argc, char **argv)
int	main(int argc, char **argv, char **envp)
{

	t_list *lst_token;
	char **split;
	t_list *lst;
	char	*command_line;
	t_btree *root;
	t_lst_env *env_list;

	(void)(argc);
	(void)(argv);
	const char	prompt[] = GRN " Airpottier_shell$ " RESET;

	while (42)
	{
		command_line = readline(prompt);
		add_history(command_line);
		printf("%s\n", command_line);

	if(primary_checker(command_line) == TRUE)
	{
		printf("The checker say 'commande is good'\n");
		root = get_btree_of_logical_op(command_line);
		add_all_pipe_sequence_in_tree(&root, command_line);
		
		/*
		split = split_by_separator(command_line, "|<>");
		
		printf("------------------------------\n");
		print_split_tab(split);
printf("------------------------------\n");
		lst_token = create_token_list(split);
		print_split_lst(lst_token);

		*/
		printf("------------------------------\n");
		env_list = convert_env_array_in_list(envp);
		execute_command_tree(root, env_list);
		
		print2D(root);
		printf("------------------------------\n");
		free(command_line);
		//__ft_calloc(-1);
	}
	else
	{	
		
		printf("The checker say 'commande is bad'\n");
	
	}

	}
	
	return (0);
}