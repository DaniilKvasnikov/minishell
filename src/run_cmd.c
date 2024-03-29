/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:56:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:56:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		run_cmd(char *path, char **args, char **envp, t_mydata *mydata)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, envp);
	else if (pid < 0)
	{
		ft_set_color(mydata, C_RED);
		ft_putendl("Fork failed to create a new process.");
		ft_set_color(mydata, C_RESET);
		return (-1);
	}
	wait(&pid);
	return (1);
}
