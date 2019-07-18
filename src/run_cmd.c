#include "ft_minishell.h"

int		run_cmd(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, NULL);
	else if (pid < 0)
	{
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	return (1);
}
