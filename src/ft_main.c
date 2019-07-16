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
		ft_printf("[%d](%s)\n", i, envp[i]);
}

void
	start_cd(char *str)
{
	char	*n_str;
	int		j;

	n_str = ft_strdup(str);
	while (n_str[0] != '\0' && n_str[0] != ' ')
	{		
		j = -1;
		while (n_str[++j] != '\0')
			n_str[j] = n_str[j + 1];
	}
	j = -1;
	if (n_str[0] == ' ')	
		while (n_str[++j] != '\0')
			n_str[j] = n_str[j + 1];
	chdir(n_str);
	ft_printf("cd [%s]\n", n_str);
	free(n_str);
}

void
	start_ls(char *str, char **argv)
{
	run_cmd("/bin/ls", argv);
	ft_printf("ls [%s]\n", str);
}

void
	start_pwd()
{
	char dir[MAXDIR];

	getcwd(dir, MAXDIR);
	ft_printf("%s\n", dir);
}

void
	start_echo(char *str, char **argv)
{
	ft_printf("echo [%s]\n", str);
}

void
	start_setenv(char *str, char **argv)
{
	ft_printf("setenv [%s]\n", str);
}

void
	start_unsetenv(char *str, char **argv)
{
	ft_printf("unsetenv [%s]\n", str);
}

void
	start_env(char *str, char **argv)
{
	ft_printf("env [%s]\n", str);
}

int
	start_prog(char *str, char **argv)
{
	char	*line;

	if (ft_strncmp(line = "exit", str, 4) == 0)
		exit(0);
	else if (ft_strncmp(line = "echo", str, 4) == 0)
		start_echo(str, argv);
	else if (ft_strncmp(line = "cd", str, 2) == 0)
		start_cd(str);
	else if (ft_strncmp(line = "setenv", str, 6) == 0)
		start_setenv(str, argv);
	else if (ft_strncmp(line = "unsetenv", str, 8) == 0)
		start_unsetenv(str, argv);
	else if (ft_strncmp(line = "env", str, 8) == 0)
		start_env(str, argv);
	else if (ft_strncmp(line = "ls", str, 2) == 0)
		start_ls(str, argv);
	else if (ft_strncmp(line = "pwd", str, 3) == 0)
		start_pwd();
	else
		return (0);
	return (1);
}

void
	change_str(char *str)
{
	int	i;
	int	j;

	while (str[0] != '\0' && str[0] == ' ')
	{		
		j = -1;
		while (str[++j] != '\0')
		{
			str[j] = str[j + 1];
		}
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			j = i;
			while (str[++j] != '\0')
			{
				str[j] = str[j + 1];
			}
		}
	}
}

int
	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*str;

	// print_envp(envp);
	signal(SIGINT, sig_handler);
	put_start_shell();
	while (get_next_line(0, &line) == 1)
	{
		str = ft_strdup(line);
		change_str(str);
		free(line);
		if (ft_strlen(str) > 0 && start_prog(str, argv) == 0)
		{
			ft_putstr("command not found\n");
		}
		put_start_shell();
		free(str);
	}
	return (0);
}
