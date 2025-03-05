/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/04 16:59:09 by sechlahb         ###   ########.fr       */
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
	pipex->fd2 = open(pipex->av[pipex->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
		perror("open failed2\n");
}
void ft_pipe(t_pipex *pipex, int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("Pipe failed\n");
		ft_free(pipex);
		exit(1);
	}
}

void	ft_first_p(t_pipex *pipex, int *pipefd)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pid1 == 0)
	{
        if (!pipex->cmd1 || pipex->cmd1[0] == NULL)
        {
            ft_free(pipex);
            exit(127);
        }
        if (pipex->fd1 == -1)
        {
            ft_free(pipex);
            exit(1);  
        }
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipex->fd1, STDIN_FILENO);
		if (execve(pipex->cmd1[0], pipex->cmd1, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);
	}
	close(pipefd[1]);
	close(pipex->fd1);
}

void	ft_second_p(t_pipex *pipex, int *pipefd)
{
	pipex->pidn = fork();
	if (pipex->pidn == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pidn == 0)
	{
		if (!pipex->cmdn || pipex->cmdn[0] == NULL)
		{
			ft_free(pipex);
			exit(127);
		}
		if (pipex->fd2 == -1)
		{
			ft_free(pipex);
			exit(1);
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(pipex->fd2, STDOUT_FILENO);
		if (execve(pipex->cmdn[0], pipex->cmdn, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);

	}
	close(pipex->fd2);
	close(pipefd[0]);
}

void ft_middle_procces(t_pipex *pipex, int *pipefd1, int *pipefd2, int i)
{
	pid_t pid;
	char **cmd;

	cmd = last_cmd(pipex, pipex->av[i]);
	pid = fork();
	if (pid == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pid == 0)
	{
		if (!cmd || cmd[0] == NULL)
		{
			ft_free(pipex);
			exit(127);
		}
		close(pipefd2[1]);
		dup2(pipefd1[0], STDIN_FILENO);
		dup2(pipefd2[1], STDOUT_FILENO);
		if (execve(cmd[0], cmd, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);

	}
	ft_free_split(cmd);
	close(pipefd2[1]);
	close(pipefd1[0]);
}

void	here_doc_first_p(t_pipex *pipex, int *pipefd)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pid1 == 0)
	{
		int fd = open("file", O_RDWR , 0644);
		if (fd == -1)
		{	ft_free(pipex);
			exit (1);
		}
        if (!pipex->cmd1 || pipex->cmd1[0] == NULL)
        {
            ft_free(pipex);
            exit(127);
        }
        if (pipex->fd1 == -1)
        {
            ft_free(pipex);
            exit(1);  
        }
		close(pipefd[0]);
		dup2(fd, STDIN_FILENO);
		close (fd);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execve(pipex->cmd1[0], pipex->cmd1, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);
		
	}
	close(fd);
	close(pipefd[1]);
}

void	here_doc_second_p(t_pipex *pipex, int *pipefd)
{
	pipex->pidn = fork();
	if (pipex->pidn == -1)
		ft_exit(pipex, "fork failure", 1);
	if (pipex->pidn == 0)
	{
		if (!pipex->cmdn || pipex->cmdn[0] == NULL)
		{
			ft_free(pipex);
			exit(127);
		}
		if (pipex->fd2 == -1)
		{
			ft_free(pipex);
			exit(1);
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);

		close (pipefd[0]);
		dup2(pipex->fd2, STDOUT_FILENO);
		close (pipex->fd2);
		if (execve(pipex->cmdn[0], pipex->cmdn, pipex->envp) == -1)
			ft_exit(pipex, "fork failure", 127);

	}
	close(pipex->fd2);
	close(pipefd[0]);
}
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int  (status2), (status1), (i);
	int (pipefd1[2]), (pipefd2[2]);

	status2 = 0;
	status1 = 0;
	i = 3;
	if (ac < 5)
		exit(1);
	ft_init(&pipex, ac, av, envp);
	///////////////////////////////////////////////////////////////////////////////////////
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ac == 6)
	{
		ft_pipe(&pipex, pipefd1);
		pipex.fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex.fd2 == -1)
			perror("open failed2\n");
		pipex.cmd1 = last_cmd(&pipex, av[3]);
		pipex.cmdn = last_cmd(&pipex, av[ac - 2]);
		int here_doc_fd = open("file", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (here_doc_fd == -1)
		{	ft_free(&pipex);
			exit (1);
		}
		char *buffer;
		while (1)
		{
			buffer = get_next_line(STDIN_FILENO);
			if (ft_strncmp(buffer, av[2], ft_strlen(av[2])) == 0)
				break;
			write (here_doc_fd, buffer, ft_strlen(buffer));
			free(buffer);
		}
		free(buffer);
		close (here_doc_fd);
		// close (pipefd1[1]);
		here_doc_first_p(&pipex, pipefd1);
		here_doc_second_p(&pipex, pipefd1);
		waitpid(pipex.pid1, &status1, WUNTRACED); 
		waitpid(pipex.pidn, &status2, WUNTRACED); 
		close(here_doc_fd);
		ft_free(&pipex);
		if (WIFEXITED(status2))
			exit(WEXITSTATUS(status2));
		else
			exit(1);
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	pipex.cmd1 = last_cmd(&pipex, av[2]);
	pipex.cmdn = last_cmd(&pipex, av[ac - 2]);
	ft_open(&pipex);
	ft_pipe(&pipex, pipefd1);
	ft_first_p(&pipex, pipefd1);
	while (i < ac - 2)
	{
		ft_pipe(&pipex, pipefd2);
		ft_middle_procces(&pipex, pipefd1, pipefd2, i);
		close (pipefd1[0]);
		close(pipefd1[1]);
		pipefd1[0] = pipefd2[0];
		pipefd1[1] = pipefd2[1];
		i++;
	}
	ft_second_p(&pipex, pipefd1);
    waitpid(pipex.pid1, &status1, WUNTRACED); 
    waitpid(pipex.pidn, &status2, WUNTRACED); 
	ft_free(&pipex);
	if (WIFEXITED(status2))
		exit(WEXITSTATUS(status2));
	else
		exit(1);
}
