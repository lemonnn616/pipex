/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:37:17 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/20 16:26:29 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_error(void)
{
	perror("Error:command not found");
	exit(0);
}

void	dup2_check(int fd1, int fd2)
{
	if (fd1 == -1 || fd2 == -1)
	{
		perror("Error:open");
		exit(0);
	}
	dup2(fd1, fd2);
}

void	execute_command(t_variables *vars, char *command, char **env)
{
	char	**args;
	int		i;

	args = ft_split(command, ' ');
	if (!args || !args[0])
	{
		i = 0;
		while (args && args[i])
			free(args[i++]);
		free(args);
		f_error();
	}
	close_all(vars);
	if (execve(true_path(args[0], env), args, env) == -1)
		perror("Command not found");
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	exit(1);
}

void	piping(t_variables *vars, char **argv, char **env, int i)
{
	vars->f1 = fork();
	if (vars->f1 == 0)
	{
		if (i == 2)
		{
			dup2_check(vars->infile, STDIN_FILENO);
			dup2_check(vars->fd[1], STDOUT_FILENO);
		}
		else if (i == 3)
		{
			dup2_check(vars->outfile, STDOUT_FILENO);
			dup2_check(vars->fd[0], STDIN_FILENO);
		}
		execute_command(vars, argv[i], env);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_variables	variables;
	int			i;

	variables.comm_count = argc - 3;
	i = 2;
	if (argc != 5)
	{
		perror("Error:Wrong arguments");
		exit(0);
	}
	variables.infile = open(argv[1], O_RDWR, 0777);
	variables.outfile = open(argv[argc - 1],
			O_RDWR | O_CREAT | O_TRUNC, 0777);
	pipe(variables.fd);
	while (i < 4)
		piping(&variables, argv, env, i++);
	close_2(variables.infile, variables.outfile);
	close_2(variables.fd[1], variables.fd[0]);
	while (wait(NULL) != -1)
		;
	return (0);
}
