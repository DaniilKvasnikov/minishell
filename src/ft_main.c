#include "ft_minishell.h"

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
	check_file(char *path)
{
	if (access(path, F_OK) != 0)
		return (0);
	else if (access(path, X_OK) != 0)
	{
		ft_printf("You dont have search access to '%s'\n", path);
		return (-1);
	}
	return (1);
}

int
	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**strs;
	t_mydata	*mydata;
	int			check_res;

	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	put_start_shell();
	while (get_next_line(0, &line) == 1)
	{
		if ((strs = ft_strsplit_argv(line, ' ')) != NULL)
		{
			if (strs[0] != NULL && ft_strlen(strs[0]) > 0)
			{
				if ((check_res = check_file(strs[0])) == 1)
					run_cmd(strs[0], strs, mydata->envp);
				else if (check_res != -1 && start_prog(strs, mydata) == 0)
					ft_printf("%s: command not found\n", strs[0]);
			}
			ft_strsplit_free(strs);
		}
		else
			ft_printf("error input\n");
		free(line);
		put_start_shell();
	}
	ft_get_envp_free(mydata->envp);
	free(mydata);
	return (0);
}
