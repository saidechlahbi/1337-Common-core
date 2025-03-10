/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:29:26 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/08 21:56:11 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>

typedef struct s_pipex
{
	char	**av;
	char	**envp;
	int		pipefd[2];
	int		fd1;
	int		fd2;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	char	*str1;
	char	*str2;
}			t_pipex;

char		**ft_splite(char const *s, char c);
void		ft_free_split(char **str);
void		ft_free(t_pipex *pipex);
void		ft_init(t_pipex *pipex, char **av, char **envp);
void		write_error(t_pipex *pipex, char *str);

#endif