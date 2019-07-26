/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:56:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 19:22:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int
	main(int argc, char **argv, char **envp)
{
	t_mydata	*mydata;

	rl_readline_name = "minishell";
	rl_attempted_completion_function = character_name_completion;
	signal(SIGINT, sig_handler);
	mydata = init_mydata(argc, argv, envp);
	if (!is_flag_ls(mydata->flags, 't'))
		ft_standart_minishell(mydata);
	else
		ft_auto_minishell(mydata);
	ft_get_envp_free(mydata->envp);
	free(mydata->flags);
	free(mydata);
	return (0);
}
