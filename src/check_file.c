/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:49:17 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:49:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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
