/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:12:10 by sechlahb          #+#    #+#             */
/*   Updated: 2025/02/14 17:29:28 by sechlahb         ###   ########.fr       */
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
	if (pipex->cmdn)
		ft_free_split(pipex->cmdn);
	if (pipex->paths)
		ft_free_split(pipex->paths);
	if (pipex->fd1)
		close (pipex->fd1);
	if (pipex->fd2)
		close (pipex->fd2);		
}
