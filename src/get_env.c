/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:45:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:45:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char
	*get_env(char *str, char **envp)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = -1;
	while (envp[++i] != 0)
		if (ft_strncmp(str, envp[i], len) == 0)
			if (envp[i][len] == '=')
				return (ft_strdup(envp[i] + len + 1));
	return (NULL);
}

int
	ft_get_envp_len(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		;
	return (i);
}

int
	ft_get_envp_free(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
		free(envp[i]);
	free(envp);
	return (i);
}

void
	print_envp(char **envp, t_mydata *mydata)
{
	int	i;

	i = -1;
	while (envp[++i] != 0)
	{
		ft_set_color(mydata, C_MAGNETA);
		ft_printf("%s\n", envp[i]);
		ft_set_color(mydata, C_RESET);
	}
}
