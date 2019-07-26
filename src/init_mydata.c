/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mydata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:45:47 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:45:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_mydata
	*init_mydata(int argc, char **argv, char **envp)
{
	t_mydata	*mydata;
	int			i;

	mydata = (t_mydata *)malloc(sizeof(t_mydata));
	mydata->argc = argc;
	mydata->argv = argv;
	mydata->envp =
		(char **)malloc(sizeof(char *) * (ft_get_envp_len(envp) + 1));
	i = -1;
	while (envp[++i] != 0)
		mydata->envp[i] = ft_strdup(envp[i]);
	mydata->envp[i] = NULL;
	mydata->flags = set_flags(argc, argv);
	return (mydata);
}
