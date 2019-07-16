#include "ft_minishell.h"

static int		run_cmd(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	// signal(SIGINT, proc_signal_handler);
	if (pid == 0)
		execve(path, args, NULL);
	else if (pid < 0)
	{
		// free(path);
		ft_putendl("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	// if (path)
	// 	free(path);
	return (1);
}

int
	main(int argc, char **argv)
{
	char	*line;

	run_cmd("/bin/ls", argv + 1);
	ft_putstr("rrhaenys:");
	while (get_next_line(0, &line) == 1)
	{
		ft_putendl(line);///bin/ls
		ft_putstr("rrhaenys:");
		free(line);
	}
	return (0);
}
