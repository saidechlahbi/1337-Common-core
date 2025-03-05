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

void	ft_init(t_pipex *pipex, int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	char	**paths;

	i = 0;
	pipex->ac = ac;
	pipex->av = av;
	pipex->envp = envp;
	while (ft_strncmp(pipex->envp[i], "PATH=", 5) != 0)
		i++;
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

char	*ft_right_path(t_pipex *pipex, char *comand)
{
	char	*str;
	char	*cmd;
	int		i;

	i = 0;
	if (!pipex->paths)
	{
		ft_free(pipex); 
		exit(1);
	}
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

char **ft_init_cmd(char *cmd)
{
	char **str;
	int (booll), (i);

	if (cmd[0] == 0)
		return NULL;
	i = 0;
	booll = 0;
	while (cmd[i] && cmd[i] != '\'')
		i++;
	if (cmd[i])
		booll = 1;
	if (booll == 1)
	{
		str = ft_splite(cmd, ' ');
		if (!str)
			return NULL;
	}else
	{
		str = ft_split(cmd, ' ');
		if (!str)
			return NULL;
	}
	return str;
}

char **last_cmd(t_pipex *pipex, char *str)
{
	char **command;
	char *a;

	command = ft_init_cmd(str);
	if (!command)
		return NULL;
	a = command[0];
	command[0] = ft_right_path(pipex, command[0]);
	free(a);
	return command;
}