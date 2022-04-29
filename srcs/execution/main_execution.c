/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:35:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/29 10:36:54 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void execute_command_tree(t_btree *root, t_lst_env *env_list)
{
	if (!root)
		return ;
	execute_command_tree(root->left, env_list);	//go->left
	if (root->token_list)
		execute_pipe_sequence(root->token_list, env_list);	//do action
	execute_command_tree(root->right, env_list);	//go->right
}

int execute_pipe_sequence(t_list *token_list, t_lst_env *env_list)
{
	t_token *token;
	// parcourir les commandes séparés par les pipes
	while (token_list)
	{
		execute_command(token_list, env_list);
		//pipe
		token_list = find_next_cmd(token_list);
		if (token_list)
		{
			token = token_list->content;
			printf("token : %s\n", token->str);
		}
	}
}


int execute_command(t_list *cmd, t_lst_env *env_list)
{
	char	**argv;
//	t_token *token;

//	token = cmd;
	expand(cmd, env_list);

	printf("TEMOIN 0:\n");
	argv = find_cmd(cmd);
	printf("TEMOIN 1:\n");
	printf("argv_arg:\n");
	print_char_two_dim_array(argv);

//	set_up_redirect_in();
//	set_up_redirect_out();
//	set_up_redirect_out_append();
//	execute();
}

char **find_cmd(t_list *cmd)
{
	t_token	*token;

	token = cmd->content;
	while (cmd && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			cmd = skip_heredoc_token(cmd);
		if (is_heredoc_token(token->type) || is_redirect_token(token->type))
			cmd = skip_two_token(cmd);
		if (cmd)
			token = cmd->content;
		if (cmd && token->type == TOK_WORD)
		{
			create_argv_cmd(cmd);
		}
		if (cmd)
			cmd = cmd->next;
	}
}

char	**create_argv_cmd(t_list *cmd)
{
	char	**argv_cmd;
	t_list	*tmp;
	t_token	*token;
	int		count;
	int		i;
	tmp = cmd;
	token = tmp->content;
	count = 0;

	while (tmp && token->type == TOK_WORD)
	{
		count++;
		tmp = tmp->next;
		token = tmp->content;
	}
	argv_cmd = __ft_calloc(sizeof(char*) * (count + 1));
	i = 0;
	tmp = cmd;
	while (i < count)
	{
		token = tmp->content;
		argv_cmd[i] = token->str;
		tmp = tmp->next;
		i++;
	}
	return (argv_cmd);
}

void expand(t_list *cmd, t_lst_env *env_list)
{
	t_token	*token;

	token = cmd->content;
	while (cmd && token->type != TOK_PIPE)
	{
		if (is_heredoc_token(token->type))
			cmd = skip_heredoc_token(cmd);
		token = cmd->content;
		if (token->type == TOK_WORD)
		{
			if (token->str);
				token->str = expand_command(token->str, env_list);
		}
		token = cmd->content;
		cmd = cmd->next;
	}
}


t_list *find_next_cmd(t_list *elem)
{
	t_token *token;

	token = elem->content;
	while (elem && token->type != TOK_PIPE)
	{
		elem = elem->next;
		if (elem)
			token = elem->content;
	}
	if (!elem)
		return (NULL); //no more command
	else
		return (elem->next); //considérant que le checker ne laisse pas passer une cmd qui se termine pas un |
}


int is_redirect_token(t_type_token token_type)
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

int is_heredoc_token(t_type_token token_type)
{
	if (token_type == TOK_HEREDOC)
		return (TRUE);
	else
		return (FALSE);
}

t_list *skip_heredoc_token(t_list *cmd)
{
	cmd = cmd->next;
	cmd = cmd->next;
	return (cmd);
}

t_list *skip_two_token(t_list *cmd)
{
	cmd = cmd->next;
	cmd = cmd->next;
	return (cmd);
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
		
		(root);
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