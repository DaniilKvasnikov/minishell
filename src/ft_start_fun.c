#include "ft_minishell.h"

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
		ft_printf("%s\n", str);
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
