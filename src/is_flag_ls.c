/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:46:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	is_flag_ls(char *flags, char flag)
{
	int	i;

	i = -1;
	while (flags[++i] != '\0')
		if (flags[i] == flag)
			return (1);
	return (0);
}
