#include "pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error("Error");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(filein);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fileout == -1)
		error("Error");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(fileout);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		error("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(fd) == -1)
		error("Error");
	pid1 = fork();
	if (pid1 == -1)
		error("Error");
	if (pid1 == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		error("Error");
	if (pid2 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}

