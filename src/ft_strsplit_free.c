/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:46:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	ft_strsplit_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}
