/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:06:08 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/18 10:32:46 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_files_check(t_variables *variables, char **argv, int argc)
{
	if (here_doc_check(argv[1]))
	{
		here_doc(variables, argv[2]);
		variables -> infile = open("here_doc", O_RDWR, 0777);
		variables -> outfile = open(argv[argc - 1],
				O_RDWR | O_CREAT | O_APPEND, 0777);
	}
	if (!(here_doc_check(argv[1])))
	{
		variables -> infile = open(argv[1], O_RDWR, 0777);
		variables -> outfile = open(argv[argc - 1],
				O_RDWR | O_CREAT | O_TRUNC, 0777);
	}
	if (here_doc_check(argv[1]))
		return (1);
	return (0);
}

void	dup2_2(int first, int second, int third, int fourth)
{
	if (first == -1 || second == -1 || third == -1 || fourth == -1)
	{
		perror("Failed dup2");
		exit(0);
	}
	dup2(first, second);
	dup2(third, fourth);
}

void	do_pipes(t_variables *variables)
{
	int	i;

	i = 0;
	while (i < variables -> comm_count)
		pipe (variables -> fd [i++]);
}

int	main(int argc, char **argv, char **env)
{
	t_variables	variables;
	int			i;

	if (argc < 5)
	{
		perror("Error:Wrong arguments");
		exit(0);
	}
	variables.comm_count = argc - 2;
	i = 2;
	i += open_files_check(&variables, argv, argc);
	do_pipes(&variables);
	while (i < argc - 1)
		piping(&variables, argv, env, i++);
	close_all(&variables);
	while (wait(NULL) != -1)
		;
	unlink("here_doc");
	return (0);
}
