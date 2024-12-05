/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:53:08 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/18 10:38:36 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef struct s_variables
{
	int	f1;
	int	f2;
	int	infile;
	int	outfile;
	int	here_doc;
	int	fd[1024][2];
	int	comm_count;
}				t_variables;

void	fn_path(char **res_split, char *argv);
char	*true_path(char *argv, char **env);
void	close_all(t_variables *variables);
char	*path_finder(char **env);
int		open_files_check(t_variables *variables, char **argv, int argc);
void	here_doc(t_variables *variables, char *lim);
int		here_doc_check(char *argv);
void	f_error(void);
void	piping(t_variables *vars, char **argv, char **env, int i);
void	setup_dup(t_variables *vars, char **argv, int i);
int		get_fd_out(t_variables *vars, int i);
int		get_fd_in(t_variables *vars, char **argv, int i);
void	execute_command(t_variables *vars, char *command, char **env);
void	dup2_2(int first, int second, int third, int fourth);

#endif