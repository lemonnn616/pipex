/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:08:25 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/18 10:18:45 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	f_error(void)
{
	perror("Error: command not found");
	exit(0);
}

char	*path_finder(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = "PATH=";
	while (env[i])
	{
		if (*env[i] == 'P')
		{
			if (!(ft_strncmp(env[i], path, 5)))
				path = env[i];
		}
		i++;
	}
	return (path);
}

void	fn_path(char **res_split, char *argv)
{
	int		i;
	char	*tmp;
	char	*new_str;

	tmp = NULL;
	new_str = NULL;
	i = 0;
	while (res_split[i])
	{
		tmp = ft_strjoin(res_split[i], "/");
		new_str = ft_strjoin(tmp, argv);
		free(res_split[i]);
		res_split[i] = new_str;
		free(tmp);
		i++;
	}
}

char	*true_path(char *argv, char **env)
{
	int		i;
	char	**res_split;
	char	**args;
	char	*path;

	if (access(argv, F_OK) == 0)
		return (argv);
	if (ft_strchr (argv, '/') != NULL)
		f_error();
	path = "PATH=";
	i = 0;
	args = ft_split(argv, ' ');
	path = path_finder(env);
	i = 0;
	res_split = ft_split(path, ':');
	fn_path(res_split, args[0]);
	while (res_split[i])
	{
		if (access(res_split[i], F_OK) == 0)
			return (res_split[i]);
		i++;
	}
	f_error();
	return (NULL);
}

void	close_all(t_variables *variables)
{
	int	i;

	i = 0;
	while (i < variables -> comm_count)
	{
		close(variables -> fd[i][0]);
		close(variables -> fd[i][1]);
		i++;
	}
	close(variables -> infile);
	close(variables -> outfile);
}
