/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:12:10 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/08 21:52:14 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free(t_pipex *pipex)
{
	if (pipex->cmd1)
		ft_free_split(pipex->cmd1);
	if (pipex->cmd2)
		ft_free_split(pipex->cmd2);
	if (pipex->paths)
		ft_free_split(pipex->paths);
	if (pipex->fd1 != -1)
		close(pipex->fd1);
	if (pipex->fd2 != -1)
		close(pipex->fd2);
}

void	write_error(t_pipex *pipex, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_free(pipex);
	exit(127);
}
