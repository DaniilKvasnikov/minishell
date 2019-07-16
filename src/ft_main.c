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

void
	curr_dir()
{	
	char dir[MAXDIR];

	getcwd(dir, MAXDIR);
	ft_printf("Current directory is %s\n", dir);
    // using the command 
    chdir("..");
	getcwd(dir, MAXDIR);
	ft_printf("Current directory is %s\n", dir);
}

void
	sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_printf("\nrrhaenys:");
	else
		ft_printf("\nrrhaenys[%d]:", signo);
}

void
	print_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
	{
		ft_printf("[%d](%s)\n", i, envp[i]);
	}
}

int
	main(int argc, char **argv, char **envp)
{
	char	*line;

	curr_dir();
	print_envp(envp);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	run_cmd("/bin/ls", argv);
	ft_putstr("rrhaenys:");
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, "exit") == 0)
			exit(1);
		ft_putendl(line);///bin/ls
		ft_putstr("rrhaenys:");
		free(line);
	}
	return (0);
}
