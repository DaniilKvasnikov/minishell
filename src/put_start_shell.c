/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_start_shell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:46:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	put_start_shell(t_mydata *mydata)
{
	char	*path;

	path = NULL;
	if (mydata != NULL)
	{
		path = get_curr_dir();
		ft_set_color(mydata, C_GREEN);
		if (is_flag_ls(mydata->flags, 'p'))
			ft_printf("%s ", path);
		ft_set_color(mydata, C_RESET);
	}
	ft_putstr("$>");
	if (path != NULL)
		free(path);
}
