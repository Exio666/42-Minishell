/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:52:44 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 09:51:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 1 -> copie fd
** 2 -> replace fd
** 3 -> close fd
*/

void	init_var_to_minus_one(int *first, int *cin, int *cout)
{
	*cin = -1;
	*cout = -1;
	*first = -1;
}

void	exit_save_fd(int cin, int cout)
{
	if (cin != -1)
		close(cin);
	if (cout != -1)
		close(cout);
	ft_putstr_fd("Copie of terminal failed\n", 2);
	__ft_calloc_env(-1);
	__ft_calloc(-1);
	rl_clear_history();
	save_fd(3);
	exit (1);
}

void	multi_dup2(int cin, int cout)
{
	int		error;

	error = dup2(cin, 0);
	if (error != -1)
		error = dup2(cout, 1);
	if (error == -1)
		exit_save_fd(cin, cout);
}

void	save_fd(int mod)
{
	static int	first;
	static int	cin;
	static int	cout;

	if (first == 0)
		init_var_to_minus_one(&first, &cin, &cout);
	if (mod == 1)
	{
		multi_close(cin, cout, -1, -1);
		cin = dup(0);
		cout = dup(1);
		if (cin == -1 || cout == -1)
			exit_save_fd(cin, cout);
	}
	else if (mod == 2)
		multi_dup2(cin, cout);
	else if (mod == 3)
	{
		multi_close(cin, cout, -1, -1);
		cin = -1;
		cout = -1;
	}
}
