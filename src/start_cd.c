/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:45:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 19:04:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int
	is_home_dir(char *path)
{
	if (path[0] == '~' && (path[1] == '\0' || path[1] == '/'))
		return (1);
	return (0);
}

char
	*ft_go_home(char *new_path, char **envp, t_mydata *mydata)
{
	char	*path;
	char	*path_res;

	path = get_env("HOME", envp);
	if (path == NULL)
	{
		ft_set_color(mydata, C_RED);
		ft_printf("HOME dont found\n");
		ft_set_color(mydata, C_RESET);
		return (NULL);
	}
	if (ft_strlen(new_path) > 2)
	{
		path_res = ft_stradd_3(path, "/", new_path + 2);
		free(path);
	}
	else
		path_res = path;
	return (path_res);
}

static char
	*get_path(char **strs, char **envp, t_mydata *data)
{
	char	*path;

	if (strs[1] == NULL)
		path = get_env("HOME", envp);
	else if (is_home_dir(strs[1]))
		path = ft_go_home(strs[1], envp, data);
	else if (ft_strcmp(strs[1], "-") == 0)
		path = get_env("OLDPWD", envp);
	else if (ft_strncmp(strs[1], "$", 1) == 0)
		path = get_env(strs[1] + 1, envp);
	else
		path = ft_strdup(strs[1]);
	return (path);
}

void
	start_cd(char **strs, char **envp, t_mydata *data)
{
	int		res;
	char	*path;
	char	*old_path;

	old_path = get_curr_dir();
	path = get_path(strs, envp, data);
	res = chdir(path);
	if (res != 0)
	{
		ft_set_color(data, C_YELLOW);
		ft_putstr_fd("cd: (", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("): No such file or directory\n", 2);
		ft_set_color(data, C_RESET);
	}
	else
		data->envp = set_envp("OLDPWD", old_path, envp);
	free(old_path);
	free(path);
}
