#include "ft_minishell.h"

char
	**set_envp(char *name, char *par, char **envp)
{
	
	int		i;
	char	**n_envp;
	char	*str;

	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(name, envp[i], ft_strlen(name)) == 0)
		{
			str = envp[i];
			envp[i] = ft_stradd_3(name, "=", par);
			free(str);
			return (envp);
		}
	n_envp = (char **)malloc(sizeof(char *) * (ft_get_envp_len(envp) + 2));
	i = -1;
	while (envp[++i] != 0)
		n_envp[i] = ft_strdup(envp[i]);
	n_envp[i] = ft_stradd_3(name, "=", par);
	n_envp[i + 1] = 0;
	ft_get_envp_free(envp);
	return (n_envp);
}

void
	start_cd(char **strs, char **envp, t_mydata *data)
{
	int		res;
	char	*path;
	char	*old_path;
	
	old_path = get_curr_dir();
	if (ft_strsplit_len(strs) == 1 || ft_strcmp(strs[1], "~") == 0)
		path = get_env("HOME", envp);
	else if (ft_strcmp(strs[1], "-") == 0)
		path = get_env("OLDPWD", envp);
	else if (ft_strncmp(strs[1], "$", 1) == 0)
		path = get_env(strs[1] + 1, envp);
	else
		path = ft_strdup(strs[1]);
	res = chdir(path);
	if (res != 0)
		ft_printf("cd: (%s): No such file or directory\n", path);
	else
		data->envp = set_envp("OLDPWD", old_path, envp);
	free(old_path);
	free(path);
}

void
	start_ls(char **str)
{
	run_cmd("/bin/ls", str);
}

void
	start_pwd(char **strs)
{
	run_cmd("/bin/pwd", strs);
}

void
	start_echo(char **strs, char **envp)
{
	char	*str;

	if (ft_strncmp(strs[1], "$", 1) == 0)
	{
		str = get_env(strs[1] + 1, envp);
		ft_printf("get=%s\n", str);
		free(str);
	}
	else
		run_cmd("/bin/echo", strs);
}

char
	**start_setenv(char **strs, char **envp)
{
	char	**n_envp;
	char	*tmp;

	if (strs[1] == NULL)
		return (envp);
	if ((tmp = ft_strchr(strs[1], '=')) == NULL && strs[2] == NULL)
		return (envp);
	if (strs[2] != NULL)
		n_envp = set_envp(strs[1], strs[2], envp);
	else
	{
		*tmp = '\0';
		n_envp = set_envp(strs[1], tmp + 1, envp);
	}
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
		start_echo(strs, mydata->envp);
	else if (ft_strncmp(line = "cd", strs[0], 2) == 0)
		start_cd(strs, mydata->envp, mydata);
	else if (ft_strncmp(line = "setenv", strs[0], 6) == 0)
		mydata->envp = start_setenv(strs, mydata->envp);
	else if (ft_strncmp(line = "unsetenv", strs[0], 8) == 0)
		start_unsetenv(strs[1], mydata->envp);
	else if (ft_strncmp(line = "env", strs[0], 8) == 0 || ft_strncmp(line = "/usr/bin/env", strs[0], 12) == 0)
		start_env(mydata->envp);
	else if (ft_strncmp(line = "ls", strs[0], 2) == 0 || ft_strncmp(line = "/bin/ls", strs[0], 7) == 0)
		start_ls(strs);
	else if (ft_strncmp(line = "pwd", strs[0], 3) == 0 || ft_strncmp(line = "/bin/pwd", strs[0], 8) == 0)
		start_pwd(strs);
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
		strs = ft_strsplit_argv(str, ' ');
		if (strs != NULL)
		{
			// ft_strsplit_print(strs);
			free(line);
			if (strs[0] != NULL && ft_strlen(strs[0]) > 0)
				if (start_prog(strs, mydata) == 0)
					ft_printf("%s: command not found\n", strs[0]);
			ft_strsplit_free(strs);
		}
		else
			ft_printf("error input\n");
		put_start_shell();
		free(str);
	}
	ft_get_envp_free(mydata->envp);
	free(mydata);
	return (0);
}
