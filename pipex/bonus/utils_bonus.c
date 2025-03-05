/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:19:26 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/05 02:59:06 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <time.h>

static void	ft_all_the_paths(t_pipex *pipex)
{
	int		i;
	char	*str;
	char	**paths;

	i = 0;
	while (pipex->envp[i] != NULL)
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
			break;
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
	if (access(comand, X_OK) == 0)
		return (ft_strdup(comand));
	while (pipex->paths[i])
	{
		str = ft_strjoin(pipex->paths[i], "/");
		if (!str)
			return (NULL);
		cmd = ft_strjoin(str, comand);
		if (!cmd)
			return (free(str), NULL);
		free(str);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void ft_initialization(int ac, char **av, char **envp, t_pipex *pipex)
{
	pipex->ac = ac;
	pipex->av = av;
	pipex->envp = envp;
	pipex->paths = NULL;
	ft_all_the_paths(pipex);
	if (!pipex->paths)
		exit(1);
}

char **cmd_giver(t_pipex *pipex, char *str)
{
	char **strings;
	char *cmd, *s;

	strings = NULL;
	strings = ft_split(str, ' ');
	if (!strings)
	{

	}
	cmd = ft_right_path(pipex, strings[0]);
	if (!cmd)
		ft_free_split(strings);
	s = strings[0];
	strings[0] = cmd;
	return (free(s), strings);
}
