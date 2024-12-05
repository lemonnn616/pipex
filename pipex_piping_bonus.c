/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_piping_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:31:47 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/18 10:32:18 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	get_fd_in(t_variables *vars, char **argv, int i)
{
	if (i == 2)
		return (vars->infile);
	else if (i == 3 && here_doc_check(argv[1]))
		return (vars->here_doc);
	else
		return (vars->fd[i - 3][0]);
}

int	get_fd_out(t_variables *vars, int i)
{
	if (i == vars->comm_count)
		return (vars->outfile);
	else
		return (vars->fd[i - 2][1]);
}

void	setup_dup(t_variables *vars, char **argv, int i)
{
	int	fd_in;
	int	fd_out;

	fd_in = get_fd_in(vars, argv, i);
	fd_out = get_fd_out(vars, i);
	if (i == 2 || i == 3)
		dup2_2(fd_in, STDIN_FILENO, fd_out, STDOUT_FILENO);
	else
		dup2_2(fd_out, STDOUT_FILENO, fd_in, STDIN_FILENO);
}

void	piping(t_variables *vars, char **argv, char **env, int i)
{
	vars->f1 = fork();
	if (vars->f1 == 0)
	{
		setup_dup(vars, argv, i);
		execute_command(vars, argv[i], env);
	}
}
