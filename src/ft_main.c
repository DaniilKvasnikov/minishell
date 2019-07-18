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
	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**strs;
	t_mydata	*mydata;

	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	put_start_shell();
	while (get_next_line(0, &line) == 1)
	{
		if ((strs = ft_strsplit_argv(line, ' ')) != NULL)
		{
			if (strs[0] != NULL && ft_strlen(strs[0]) > 0)
				if (start_prog(strs, mydata) == 0)
					ft_printf("%s: command not found\n", strs[0]);
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
