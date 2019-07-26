/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:45:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:49:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char
	*get_curr_dir(void)
{
	char *dir;

	dir = (char *)malloc(sizeof(char) * (MAXDIR + 1));
	getcwd(dir, MAXDIR);
	return (dir);
}
