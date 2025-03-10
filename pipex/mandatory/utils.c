/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:19:26 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/08 23:27:11 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_all_the_paths(t_pipex *pipex)
{
	int		i;
	char	*str;
	char	**paths;

	i = 0;
	while (pipex->envp[i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (pipex->envp[i] == NULL)
		return ;
	str = ft_strtrim(pipex->envp[i], "PATH=");
	if (!str)
		return ;
	paths = ft_split(str, ':');
	if (!paths)
	{
		free(str);
		return ;
	}
	pipex->paths = paths;
	free(str);
}

static char	*ft_right_path(t_pipex *pipex, char *comand)
{
	char	*str;
	char	*cmd;
	int		i;

	i = 0;
	if (!pipex->paths)
		(ft_free(pipex)), (exit(1));
	if (access(comand, X_OK) == 0)
		return (ft_strdup(comand));
	while (pipex->paths[i])
	{
		str = ft_strjoin(pipex->paths[i++], "/");
		if (!str)
			return (NULL);
		cmd = ft_strjoin(str, comand);
		if (!cmd)
			return (free(str), NULL);
		free(str);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
	}
	return (NULL);
}

static void	ft_exit(t_pipex *pipex)
{
	if (!pipex->cmd1)
	{
		ft_free(pipex);
		exit(1);
	}
	else if (!pipex->cmd2)
	{
		ft_free(pipex);
		exit(1);
	}
}

static void	initialisation(t_pipex *pipex, char **av, char **envp)
{
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->paths = NULL;
	pipex->av = av;
	pipex->envp = envp;
	pipex->str1 = av[2];
	pipex->str2 = av[3];
	pipex->fd1 = -1;
	pipex->fd2 = -1;
}

void	ft_init(t_pipex *pipex, char **av, char **envp)
{
	char	*a;
	char	*b;

	initialisation(pipex, av, envp);
	ft_all_the_paths(pipex);
	pipex->cmd1 = ft_split(pipex->av[2], ' ');
	pipex->cmd2 = ft_split(pipex->av[3], ' ');
	ft_exit(pipex);
	a = pipex->cmd1[0];
	b = pipex->cmd2[0];
	if (!a || !a[0])
		pipex->cmd1[0] = NULL;
	if (!b || !b[0])
		pipex->cmd2[0] = NULL;
	if (a)
		pipex->cmd1[0] = ft_right_path(pipex, pipex->cmd1[0]);
	if (b)
		pipex->cmd2[0] = ft_right_path(pipex, pipex->cmd2[0]);
	if (a)
		free(a);
	if (b)
		free(b);
}
