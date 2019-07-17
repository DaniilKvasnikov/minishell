#include "ft_minishell.h"

void
	put_start_shell()
{
	ft_putstr("$>");
}

char
	*get_env(char *str, char **envp)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(str, envp[i], len) == 0)
			if (envp[i][len] == '=')
				return (ft_strdup(envp[i] + len + 1));
	return (NULL);
}

int
	ft_get_envp_len(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		;
	return (i);
}

int
	ft_get_envp_free(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		free(envp[i]);
	free(envp);
	return (i);
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
	start_cd(char **strs, char **envp)
{
	int		res;
	char	*path;
	
	if (ft_strsplit_len(strs) >= 2)
	{
		if (ft_strcmp(strs[1], "~") == 0)
			path = get_env("HOME", envp);
		if (ft_strcmp(strs[1], "-") == 0)
			path = get_env("OLDPWD", envp);
		else if (ft_strncmp(strs[1], "$", 1) == 0)
			path = get_env(strs[1] + 1, envp);
		else
			path = ft_strdup(strs[1]);
		res = chdir(path);
		if (res != 0)
			ft_printf("cd: %s: No such file or directory\n", strs[1]);
		free(path);
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
	char	*str;

	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(strs[1], envp[i], ft_strlen(strs[1])) == 0)
		{
			str = envp[i];
			envp[i] = ft_strdup(strs[1]);
			free(str);
			return (envp);
		}
	n_envp = (char **)malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (envp[++i] != 0)
		n_envp[i] = envp[i];
	n_envp[i] = ft_stradd_3(strs[1], "=", strs[2]);
	n_envp[i + 1] = 0;
	ft_get_envp_free(envp);
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
			free(envp[i]);
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
		start_cd(strs, mydata->envp);
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
	int			i;

	mydata = (t_mydata *)malloc(sizeof(t_mydata));
	mydata->argc = argc;
	mydata->argv = argv;
	mydata->envp = (char **)malloc(sizeof(char *) * (ft_get_envp_len(envp) + 1));
	i = -1;
	while (envp[++i] != 0)
		mydata->envp[i] = ft_strdup(envp[i]);
	mydata->envp[i] = NULL;
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
	ft_get_envp_free(mydata->envp);
	free(mydata);
	return (0);
}
