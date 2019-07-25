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
	mydata->flags = set_flags(argc, argv);
	return (mydata);
}

int
	check_file(char *path)
{
	char	buf[1024];
	int		len;

	if (access(path, F_OK) != 0)
		return (0);
	else if (access(path, X_OK) != 0)
	{
		ft_putstr_fd("You dont have search access to '", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("'\n", 2);
		return (-1);
	}
	return (1);
}

void
	one_command(char *line, t_mydata *mydata)
{
	char		**strs;
	int			check_res;

	if ((strs = ft_strsplit_argv(line, ' ')) != NULL)
	{
		if (strs[0] != NULL && ft_strlen(strs[0]) > 0)
		{
			if ((check_res = check_file(strs[0])) == 1)
				run_cmd(strs[0], strs, mydata->envp);
			else if (check_res != -1 && start_prog(strs, mydata) == 0)
			{
				ft_putstr_fd(strs[0], 2);
				ft_putstr_fd(": command not found\n", 2);
			}
		}
		ft_strsplit_free(strs);
	}
	else
		ft_putstr_fd("error input\n", 2);
	free(line);
}

void
	more_commands(char *line, t_mydata *mydata)
{
	char		**strs;
	int			i;

	if ((strs = ft_strsplit(line, ';')) != NULL)
	{
		i = -1;
		while (strs[++i] != NULL)
			one_command(ft_strdup(strs[i]), mydata);
		ft_strsplit_free(strs);
	}
	else
		ft_putstr_fd("error input\n", 2);
	free(line);
	put_start_shell(mydata);
}

int
	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_mydata	*mydata;

	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	put_start_shell(mydata);
	while (get_next_line(0, &line) == 1)
	{
		more_commands(line, mydata);
	}
	ft_get_envp_free(mydata->envp);
	free(mydata->flags);
	free(mydata);
	return (0);
}
