#include "ft_minishell.h"

int
	is_home_dir(char *path)
{
	if (path[0] == '~' && (path[1] == '\0' || path[1] == '/'))
		return (1);
	return (0);
}

char
	*ft_go_home(char *new_path, char **envp)
{
	char	*path;
	char	*path_res;

	path = get_env("HOME", envp);
	if (path == NULL)
	{
		ft_printf("HOME dont found\n");
		return (NULL);
	}
	if(ft_strlen(new_path) > 2)
	{
		path_res = ft_stradd_3(path, "/", new_path + 2);
		free(path);
	}
	else
		path_res = path;
	return (path_res);
}

void
	start_cd(char **strs, char **envp, t_mydata *data)
{
	int		res;
	char	*path;
	char	*old_path;
	
	old_path = get_curr_dir();
	if (is_home_dir(strs[1]))
	{
		path = ft_go_home(strs[1], envp);
	}
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
