#include "ft_minishell.h"

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
