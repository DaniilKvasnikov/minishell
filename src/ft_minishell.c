/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:59:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 19:22:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void
	command_not_found(t_mydata *mydata, char **strs)
{
	ft_set_color(mydata, C_RED);
	ft_putstr_fd(strs[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_set_color(mydata, C_RESET);
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
				command_not_found(mydata, strs);
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

void
	ft_standart_minishell(t_mydata *mydata)
{
	int			res;
	char		*line;

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

void
	ft_auto_minishell(t_mydata *mydata)
{
	char		*str;
	char		*path;
	char		*buffer;

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
