/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:01:16 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/10 13:58:10 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// export a="cho a"

int main(int argc, char **argv, char **envp)
{
	(void)(argc);
	(void)(argv);
	
	launch_test_a_equal_cho_a(envp);
	return (0);
}

void	launch_test_a_equal_cho_a(char **envp)
{
	printf(RED "a=\"cho a\"\n" RESET);

	test0(envp);
	test1(envp);
	test2(envp);
	test3(envp);
	test4(envp);
	test5(envp);
	test6(envp);
	test7(envp);
	test8(envp);
	test_8_bis(envp);
}

void test0(char **envp)
{
	char	command_line[] = "echo \"e\"\"$a\"\"e\"";
	t_btree *root;
	t_lst_env *env_list;

	root = NULL;
	printf(GRN "Test 0 : echo \"e\"\"$a\"\"e\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [echo a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|echo a| : EXPECTED\n");

	printf("\n");
}

void test1(char **envp)
{
	char	command_line[] = "echo e\"$a\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 1 : echo e\"$a\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [echo a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|echo a| : EXPECTED\n");

	printf("\n");
}

void test2(char **envp)
{
	char	command_line[] = "echo $a";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 2 : echo $a\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [cho a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|cho a| : EXPECTED\n");

	printf("\n");
}

void test3(char **envp)
{
	char	command_line[] = "echo \"$a\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 3 : echo \"$a\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [cho a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|cho a| : EXPECTED\n");

	printf("\n");
}


void test4(char **envp)
{
	char	command_line[] = "echo \'$a\'";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 4 : echo \'$a\'n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [$a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|$a| : EXPECTED\n");

	printf("\n");
}

void test5(char **envp)
{
	char	command_line[] = "e$a";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 5 : e$a\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|a| : EXPECTED\n");

	printf("\n");
}

void test6(char **envp)
{
	char	command_line[] = "e\"$a\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 6 : e\"$a\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|echo a: command not found| : EXPECTED\n");

	printf("\n");
}

void test7(char **envp)
{
	char	command_line[] = "e\'$a\'";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 7 : e\'$a\'\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [e$a]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|Command 'e$a' not found| : EXPECTED\n");

	printf("\n");
}

void test8(char **envp)
{
	char	command_line[] = "echo \"\" $a \"\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 8 ; echo \"\" $a \"\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | []  ->  0 | [cho]  ->  0 | [a]  ->  0 | []  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("| cho a |: EXPECTED\n");

	printf("\n");
}


void test_8_bis(char **envp)
{
	char	command_line[] = "echo \"\" \"$a\" \"\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 8_bis : echo \"\" \"$a\" \"\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | []  ->  0 | [cho a]  ->  0 | []  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("| cho a | : EXPECTED\n");

	printf("\n");
}








/*
export a="    bonjour    "
*/

void	launch_test_a_equal_bonjour_with_space(char **envp)
{
	printf(RED "a=\"    bonjour    \"\n" RESET);
	test9(envp);
	test10(envp);
	test11(envp);
	test12(envp);
	test13(envp);
}

void test9(char **envp)
{
	char	command_line[] = "echo $a";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 9 : echo $a\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [bonjour]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|bonjour| : EXPECTED\n");

	printf("\n");
}

void test10(char **envp)
{
	char	command_line[] = "echo \"$a\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 10 : echo \"$a\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [    bonjour    ]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|    bonjour    | : EXPECTED\n");

	printf("\n");
}

void test11(char **envp)
{
	char	command_line[] = "echo \"$a\"\"madame\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 11 : echo \"$a\"\"madame\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [   bonjour    madame]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|   bonjour    madame| : EXPECTED\n");

	printf("\n");
}

void test12(char **envp)
{
	char	command_line[] = "echo $a\"madame\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 12 : echo $a\"madame\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [bonjour]  ->  0 | [madame]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|   bonjour    madame| : EXPECTED\n");

	printf("\n");
}

void test13(char **envp)
{
	char	command_line[] = "echo e\"$a\"\"madame\"";
	t_btree *root;
	t_lst_env *env_list;

	printf(GRN "Test 13 : echo e\"$a\"\"madame\"\n" RESET);
	root = get_btree_of_logical_op(command_line);
	add_all_pipe_sequence_in_tree(&root, command_line);
	printf("0 | [echo]  ->  0 | [e   bonjour    madame]  ->  NULL : EXPECTED\n");
	env_list = convert_env_array_in_list(envp);
	execute_command(root->token, &env_list);
	printf("|e   bonjour    madame| : EXPECTED\n");

	printf("\n");
}