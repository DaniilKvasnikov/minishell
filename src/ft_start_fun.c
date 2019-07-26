/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:46:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	start_ls(char **str, char **envp, t_mydata *mydata)
{
	ft_set_color(mydata, C_YELLOW);
	run_cmd("/bin/ls", str, envp, mydata);
	ft_set_color(mydata, C_RESET);
}

void
	start_pwd(char **strs, char **envp, t_mydata *mydata)
{
	ft_set_color(mydata, C_YELLOW);
	run_cmd("/bin/pwd", strs, envp, mydata);
	ft_set_color(mydata, C_RESET);
}

void
	start_echo(char **strs, char **envp, t_mydata *mydata)
{
	char	*str;

	if (ft_strncmp(strs[1], "$", 1) == 0)
	{
		str = get_env(strs[1] + 1, envp);
		ft_set_color(mydata, C_CYAN);
		ft_printf("%s\n", str);
		ft_set_color(mydata, C_RESET);
		free(str);
	}
	else
	{
		ft_set_color(mydata, C_CYAN);
		run_cmd("/bin/echo", strs, envp, mydata);
		ft_set_color(mydata, C_RESET);
	}
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
