/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:17:17 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/17 17:58:11 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_variables
{
	int	f1;
	int	f2;
	int	infile;
	int	outfile;
	int	fd[2];
	int	comm_count;
}				t_variables;

void	fn_path(char **res_split, char *argv);
char	*true_path(char *argv, char **env);
void	close_all(t_variables *variables);
void	close_2(int first, int second);
char	*path_finder(char **env);
void	open_files(t_variables *variables, char **argv, int argc);
void	f_error(void);
void	execute_command(t_variables *vars, char *command, char **env);

#endif