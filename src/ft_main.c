#include "ft_minishell.h"

char *character_names[] = {
	"cd", "echo", "env", "setenv", "unsetenv", "pwd", "exit",
	"ls", "clear", (char*)NULL
};


char **
character_name_completion(const char *text, int start, int end)
{
	rl_attempted_completion_over = 1;
	return rl_completion_matches(text, character_name_generator);
}

char *
character_name_generator(const char *text, int state)
{
	static int list_index, len;
	char *name;

	if (!state) {
		list_index = 0;
		len = ft_strlen(text);
	}

	while ((name = character_names[list_index++])) {
		if (ft_strncmp(name, text, len) == 0) {
			return ft_strdup(name);
		}
	}

	return NULL;
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
	mydata->flags = set_flags(argc, argv);
	return (mydata);
}

int
	check_file(char *path, t_mydata *mydata)
{
	if (access(path, F_OK) != 0)
		return (0);
	else if (access(path, X_OK) != 0)
	{
		ft_set_color(mydata, C_RED);
		ft_putstr_fd("You dont have search access to '", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("'\n", 2);
		ft_set_color(mydata, C_RESET);
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
			if ((check_res = check_file(strs[0], mydata)) == 1)
				run_cmd(strs[0], strs, mydata->envp, mydata);
			else if (check_res != -1 && start_prog(strs, mydata) == 0)
			{
				ft_set_color(mydata, C_RED);
				ft_putstr_fd(strs[0], 2);
				ft_putstr_fd(": command not found\n", 2);
				ft_set_color(mydata, C_RESET);
			}
		}
		ft_strsplit_free(strs);
	}
	else
	{
		ft_set_color(mydata, C_RED);
		ft_putstr_fd("error input\n", 2);
		ft_set_color(mydata, C_RESET);
	}
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
	{
		ft_set_color(mydata, C_RED);
		ft_putstr_fd("error input\n", 2);
		ft_set_color(mydata, C_RESET);
	}
	free(line);
	ft_putstr("\r");
}

int
	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_mydata	*mydata;
	int			res;
	char		*buffer;
	char		*str;
	char		*path;

	rl_readline_name = "minishell";
	rl_attempted_completion_function = character_name_completion;
	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	if (!is_flag_ls(mydata->flags, 't'))
	{
		put_start_shell(mydata);
		while ((res = get_next_line(0, &line)) != -1)
		{
			if (res == 1)
				more_commands(line, mydata);
			else
				ft_putendl("");
			put_start_shell(mydata);
		}
	}
	else
	{
		while (42)
		{
			if (!is_flag_ls(mydata->flags, 'p'))
				path = ft_strdup("$>");
			else
			{
				path = get_curr_dir();
				str = ft_stradd_3(C_BLUE, path, C_RESET);
				free(path);
				path = ft_stradd_3(str, " ", "$>");
				free(str);
			}
			if ((buffer = readline(path)) != NULL)
				more_commands(buffer, mydata);
			else
				ft_putendl("");
			free(path);
		}
	}
	ft_get_envp_free(mydata->envp);
	free(mydata->flags);
	free(mydata);
	return (0);
}
