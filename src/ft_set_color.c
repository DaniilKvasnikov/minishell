/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:44:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:44:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	ft_set_color_fd(t_mydata *mydata, char *color, int fd)
{
	if (mydata != NULL)
	{
		if (is_flag_ls(mydata->flags, 'c'))
			ft_putstr_fd(color, fd);
	}
}

void
	ft_set_color(t_mydata *mydata, char *color)
{
	ft_set_color_fd(mydata, color, 0);
}
