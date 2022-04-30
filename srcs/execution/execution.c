/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:56:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/30 15:02:48 by rpottier         ###   ########.fr       */
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
		token = find_first_token_next_cmd(token);
	}
}

void	execute_command(t_lst_token *token, t_lst_env *env_list)
{
	char	**argv;

	expand(token, env_list);
	tokenisation_post_expand(token);
	argv = create_argv_cmd(token);
/*	if (argv)
	{	
		printf("-----------------\n");
		printf("argv_arg:\n");
		print_char_two_dim_array(argv);
		printf("-----------------\n");
	}
*/
//	set_up_redirect_in();
//	set_up_redirect_out();
//	set_up_redirect_out_append();
//	execute();
}
