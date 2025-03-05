/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/05 01:41:11 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exit(t_pipex *pipex, char *str, int status)
{
	perror(str);
	perror("\n");
	ft_free(pipex);
	exit(status);
}

void	ft_open(t_pipex *pipex)
{
	pipex->fd1 = open(pipex->av[1], O_RDONLY, 0644);
	if (pipex->fd1 == -1)
		perror("open failed1\n");
	pipex->fd2 = open(pipex->av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
		perror("open failed2\n");
	if (pipe(pipex->pipefd) == -1)
	{
		perror("Pipe failed\n");
		ft_free(pipex);
		exit(1);
	}
}

void	ft_first_p(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pid1 == 0)
	{
        if (pipex->cmd1[0] == NULL)
        {
            ft_free(pipex);
            exit(127);
        }
        if (pipex->fd1 == -1)
        {
            ft_free(pipex);
            exit(1);  
        }
		close(pipex->pipefd[0]);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		dup2(pipex->fd1, STDIN_FILENO);
		if (execve(pipex->cmd1[0], pipex->cmd1, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);
	}
	close(pipex->pipefd[1]);
	close(pipex->fd1);
}

void	ft_second_p(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pid2 == 0)
	{
		if (pipex->cmd2[0] == NULL)
		{
			ft_free(pipex);
			exit(127);
		}
		if (pipex->fd2 == -1)
		{
			ft_free(pipex);
			exit(1);
		}
		close(pipex->pipefd[1]);
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->fd2, STDOUT_FILENO);
		if (execve(pipex->cmd2[0], pipex->cmd2, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);

	}
	close(pipex->fd2);
	close(pipex->pipefd[0]);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int (status1), (status2) ;

	status1 = 0;
	status2 = 0;
	if (ac != 5 || av[2][0] == 0 || av[3][0] == 0)
		exit(1);
	ft_init(&pipex, av, envp);
	ft_open(&pipex);
	ft_first_p(&pipex);
	ft_second_p(&pipex);
	
	waitpid(pipex.pid1, &status1, 0);
    waitpid(pipex.pid2, &status2, 0); 
	
	ft_free(&pipex);
	if (WIFEXITED(status2))
		exit(WEXITSTATUS(status2));
	else
		exit(1); 
}
