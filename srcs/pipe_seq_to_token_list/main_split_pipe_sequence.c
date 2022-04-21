/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_split_pipe_sequence.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:08:00 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 21:59:51 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "echo a && echo b '|| (echo c || echo d)' && echo e"

# include "minishell.h"

int	main(int argc, char **argv)
{
	char **split;
	t_list	*lst;

	if (argc < 2)
	{
		printf("NEED_ARG\n");
		return (1);
	}
	(void)(argv);
	printf("%d\n", argc);
//	printf("%s\n\n", argv[1]);
	char str[] = "\"\"    bonjour    monsieur   \"\"";
	printf("%s\n\n", str);
	split = split_by_separator(str, "|<>");
	print_split_tab(split);
	
	lst = create_token_list(split);
		print_split_lst(lst);

	__ft_calloc(-1);
	return (0);
}