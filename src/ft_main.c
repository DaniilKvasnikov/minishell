#include "ft_minishell.h"

void
	put_start_shell()
{
	ft_putstr("$>");
}

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
	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		put_start_shell();
	}
}

void
	print_envp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		ft_printf("%s\n", envp[i]);
}

void
	start_cd(char **strs)
{
	int	res;
	
	if (ft_strsplit_len(strs) >= 2)
	{
		if (ft_strcmp(strs[1], "~") == 0)
			res = chdir("/Users/rrhaenys");
		else
			res = chdir(strs[1]);
		if (res != 0)
			ft_printf("cd: %s: No such file or directory\n", strs[1]);
	}
}

void
	start_ls(char **str, char **argv)
{
	run_cmd("/bin/ls", str);
}

void
	start_pwd()
{
	char dir[MAXDIR];

	getcwd(dir, MAXDIR);
	ft_printf("%s\n", dir);
}

void
	start_echo(char **strs, char **argv)
{
	run_cmd("/bin/echo", strs);
}

char
	**start_setenv(char **strs, char **envp)
{
	int		i;
	int		j;
	char	**n_envp;

	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(strs[1], envp[i], ft_strlen(strs[1])) == 0)
		{
			envp[i] = ft_strdup(strs[1]);
			return (envp);
		}
	n_envp = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (envp[++i] != 0)
		n_envp[i] = envp[i];
	n_envp[i] = ft_strdup(strs[1]);
	n_envp[i + 1] = 0;
	return (n_envp);
}

void
	start_unsetenv(char *str, char **envp)
{
	int	i;
	int	j;

	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(str, envp[i], ft_strlen(str)) == 0)
		{
			j = i - 1;
			while (envp[++j] != 0)
				envp[j] = envp[j + 1];
		}
}

void
	start_env(char **envp)
{
	print_envp(envp);
}

int
	start_prog(char **strs, t_mydata *mydata)
{
	char	*line;

	if (ft_strncmp(line = "exit", strs[0], 4) == 0)
		exit(0);
	else if (ft_strncmp(line = "echo", strs[0], 4) == 0)
		start_echo(strs, mydata->argv);
	else if (ft_strncmp(line = "cd", strs[0], 2) == 0)
		start_cd(strs);
	else if (ft_strncmp(line = "setenv", strs[0], 6) == 0)
		mydata->envp = start_setenv(strs, mydata->envp);
	else if (ft_strncmp(line = "unsetenv", strs[0], 8) == 0)
		start_unsetenv(strs[1], mydata->envp);
	else if (ft_strncmp(line = "env", strs[0], 8) == 0)
		start_env(mydata->envp);
	else if (ft_strncmp(line = "ls", strs[0], 2) == 0)
		start_ls(strs, mydata->argv);
	else if (ft_strncmp(line = "pwd", strs[0], 3) == 0)
		start_pwd();
	else
		return (0);
	return (1);
}

t_mydata
	*init_mydata(int argc, char **argv, char **envp)
{
	t_mydata	*mydata;

	mydata = (t_mydata *)malloc(sizeof(t_mydata));
	mydata->argc = argc;
	mydata->argv = argv;
	mydata->envp = envp;
	return (mydata);
}

int
	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		*str;
	char		**strs;
	t_mydata	*mydata;

	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	put_start_shell();
	while (get_next_line(0, &line) == 1)
	{
		str = ft_strdup(line);
		strs = ft_strsplit(str, ' ');
		free(line);
		if (strs[0] != NULL && ft_strlen(strs[0]) > 0)
			if (start_prog(strs, mydata) == 0)
				ft_printf("%s: command not found\n", strs[0]);
		put_start_shell();
		ft_strsplit_free(strs);
		free(str);
	}
	free(mydata);
	return (0);
}
