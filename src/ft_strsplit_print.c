/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:46:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	ft_strsplit_print(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		ft_putendl(strs[i]);
}
