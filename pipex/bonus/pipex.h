/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:29:26 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/02 14:01:57 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
#define PIPEX_H

#include "../libft/libft.h"
#include <fcntl.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct s_pipex{
    int ac;
    char **av;
    char **envp;
    int fd1;
    int fd2;
    pid_t pid1;
    pid_t pidn;
    char **paths;
}   t_pipex;


void ft_initialization(int ac, char **av, char **envp, t_pipex *pipex);
char **cmd_giver(t_pipex *pipex, char *str);

void    ft_free_split(char **str);
void    ft_free(t_pipex *pipex);

///// get next line ////
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

#endif