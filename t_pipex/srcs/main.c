/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:37:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/25 11:06:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define READ_END 0
#define WRITE_END 1

void	first_pipe(int pipe_stock[2], char *file, char *commande)
{
	int fd_file;
	char buffer[100];
	ssize_t nbytes;

	(void)commande;
	fd_file = open(file, O_RDONLY);
	dup2(fd_file, STDIN_FILENO);
	close(fd_file);
	close(pipe_stock[0]);
	dup2(pipe_stock[1], STDOUT_FILENO);
	close(pipe_stock[1]);
	while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
	exit(1);
}

void	pipe_to_pipe(int new_pipe[2], int old_pipe[2], char *commande)
{
	char buffer[100];
	size_t nbytes;

	(void)commande;
	close(old_pipe[1]);
	dup2(old_pipe[0], STDIN_FILENO);
	close(old_pipe[0]);
	close(new_pipe[0]);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
	exit(1);
}

void	last_pipe(int pipe[2], char *file, char *commande)
{
	int fd_file;
	char buffer[100];
	ssize_t nbytes;

	(void)commande;
	fd_file = open(file ,O_WRONLY | O_CREAT , 00777);
	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	dup2(fd_file, STDOUT_FILENO);
	close(fd_file);
	while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
}

int pipex(int ac, char **av, char **envp)
{
	int pipe_stock[2];
	int new_pipe[2];
	int	i;
	int pid;
	(void)envp;

	i = 3;
	pipe(pipe_stock);
	pid = fork();
	if (pid == 0)
		first_pipe(pipe_stock, av[1], av[2]);
	while (i < ac - 1)
	{
		pipe(new_pipe);
		pid = fork();
		if (pid == 0)
			pipe_to_pipe(new_pipe, pipe_stock, av[i]);
		close(pipe_stock[0]);
		close(pipe_stock[1]);
		if (i < ac - 2)
		{
			pipe_stock[0] = new_pipe[0];
			pipe_stock[1] = new_pipe[1];
			pipe(new_pipe);
		}
		i++;
	}
	if (pid != 0)
		last_pipe(new_pipe, av[i], av[i + 1]);
	close(new_pipe[0]);
	close(new_pipe[1]);
	while (waitpid(-1, NULL, 0) > 0) //Permet au programe principale d'attendre tout les enfants
			;
	return (0);
}

int main(int ac, char **av, char **envp)
{
	(void)envp;
	if (ac < 5)
	{
		printf("Bad number of argument\n");
		return (1);
	}
	return (pipex(ac, av, envp));	
}
//todo : define READ_END && WRITE_END

/*
int main(int ac, char **av)
{
	(void)ac;
	
	int fd_in = open(av[1], O_RDONLY);
	int fd_out = open(av[4],O_WRONLY | O_CREAT , 00777);
	
	int FD_in_to_Cmd1[2];
	int Cmd1_to_Cmd2[2];
	
	char buffer[100];
	ssize_t nbytes;

	pipe(FD_in_to_Cmd1);
	pipe(Cmd1_to_Cmd2);
	
	if (fork() > 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(FD_in_to_Cmd1[1], STDOUT_FILENO);

		close(fd_in);
		close(FD_in_to_Cmd1[0]);
		close(FD_in_to_Cmd1[1]);
		close(Cmd1_to_Cmd2[1]);
		close(Cmd1_to_Cmd2[0]);
		close(fd_out);

		while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
	}
	else if (fork() > 0)
	{
		dup2(FD_in_to_Cmd1[0], STDIN_FILENO);
		dup2(Cmd1_to_Cmd2[1], STDOUT_FILENO);

		close(fd_in);
		close(FD_in_to_Cmd1[0]);
		close(FD_in_to_Cmd1[1]);
		close(Cmd1_to_Cmd2[1]);
		close(Cmd1_to_Cmd2[0]);
		close(fd_out);

		while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
	}
	else
	{
		dup2(Cmd1_to_Cmd2[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);


		close(fd_in);
		close(FD_in_to_Cmd1[0]);
		close(FD_in_to_Cmd1[1]);
		close(Cmd1_to_Cmd2[1]);
		close(Cmd1_to_Cmd2[0]);
		close(fd_out);
		
		while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
			write(STDOUT_FILENO, buffer, nbytes);
	}
}*/
/*
int main(void)
{
    int ABtoC[2];
    pipe(ABtoC);

    if (fork() > 0)
    {
        // Process A
        close(ABtoC[0]);
        dup2(ABtoC[1], STDOUT_FILENO);
        close(ABtoC[1]);     // Close this too!
        // Process A writing to C
        for (int i = 0; i < 100; i++)
        {
            write(STDOUT_FILENO, "Hi\n", sizeof("Hi\n")-1);
            usleep(5000);
        }
    }
    else if (fork() > 0)
    {
        // Process B
        close(ABtoC[0]);
        dup2(ABtoC[1], STDOUT_FILENO);
        close(ABtoC[1]);
        // Process B writing to C
        for (int i = 0; i < 100; i++)
        {
            write(STDOUT_FILENO, "Lo\n", sizeof("Lo\n")-1);
            usleep(5000);
        }
    }
    else
    {
		char buffer[100];
		ssize_t nbytes;
        close(ABtoC[1]);
        dup2(ABtoC[0], STDIN_FILENO);
        close(ABtoC[0]);
        // Process C reading from both A and B
        while ((nbytes = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
            write(STDOUT_FILENO, buffer, nbytes);
    }
    return(0);
}*/