#include "ft_minishell.h"

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
	else if (ft_strncmp(line = "setenv", strs[0], 6) == 0 || ft_strncmp(line = "export", strs[0], 6) == 0)
		mydata->envp = start_setenv(strs, mydata->envp);
	else if (ft_strncmp(line = "unsetenv", strs[0], 8) == 0)
		start_unsetenv(strs[1], mydata->envp);
	else if (ft_strncmp(line = "env", strs[0], 8) == 0 || ft_strncmp(line = "/usr/bin/env", strs[0], 12) == 0)
		print_envp(mydata->envp);
	else if (ft_strncmp(line = "ls", strs[0], 2) == 0 || ft_strncmp(line = "/bin/ls", strs[0], 7) == 0)
		start_ls(strs);
	else if (ft_strncmp(line = "pwd", strs[0], 3) == 0 || ft_strncmp(line = "/bin/pwd", strs[0], 8) == 0)
		start_pwd(strs);
	else
		return (0);
	return (1);
}
