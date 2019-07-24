#include "ft_minishell.h"

char
	*comm_path(char *name, char *path)
{
	char	**paths;
	int		i;
	char	*res;

	paths = ft_strsplit(path, ':');
	i = -1;
	res = NULL;
	while (paths[++i] != NULL)
	{
		res = ft_stradd_3(paths[i], "/", name);
		if (check_file(res) == 1)
			break ;
		free(res);
		res = NULL;
	}
	ft_strsplit_free(paths);
	return (res);
}

int
	env_funs(char **strs, t_mydata *mydata)
{
	if (ft_strncmp("setenv", strs[0], 6) == 0)
		mydata->envp = start_setenv(strs, mydata->envp);
	else if (ft_strncmp("unsetenv", strs[0], 8) == 0)
		start_unsetenv(strs[1], mydata->envp);
	else if (ft_strncmp("env", strs[0], 8) == 0)
		print_envp(mydata->envp);
	else
		return (0);
	return (1);
}

int
	start_prog(char **strs, t_mydata *mydata)
{
	char	*path;

	if (ft_strncmp("exit", strs[0], 4) == 0)
		exit(0);
	if (env_funs(strs, mydata) == 1)
		return (1);
	path = get_env("PATH", mydata->envp);
	if (path == NULL)
		return (0);
	char *res = comm_path(strs[0], path);
	if (res == NULL)
		return (0);
	free(res);
	if (ft_strncmp("echo", strs[0], 4) == 0)
		start_echo(strs, mydata->envp);
	else if (ft_strncmp("cd", strs[0], 2) == 0)
		start_cd(strs, mydata->envp, mydata);
	else if (ft_strncmp("ls", strs[0], 2) == 0)
		start_ls(strs, mydata->envp);
	else if (ft_strncmp("pwd", strs[0], 3) == 0)
		start_pwd(strs, mydata->envp);
	else
		return (0);
	return (1);
}
