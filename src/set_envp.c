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