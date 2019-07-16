/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:19:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:58:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_length(t_spec *elem, char c)
{
	char *str;

	str = "hljzL";
	if (ft_strchr(str, c) == NULL)
		return (0);
	if (c == 'h' && elem->length == 1)
		elem->length = 2;
	else if (c == 'h')
		elem->length = 1;
	else if (c == 'l' && elem->length == 3)
		elem->length = 4;
	else if (c == 'l')
		elem->length = 3;
	else if (c == 'j')
		elem->length = 5;
	else if (c == 'z')
		elem->length = 6;
	else
		elem->length = 7;
	return (1);
}

int				get_length(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	while (*str != '\0' && index < 2 && is_length(elem, *str++) != 0)
		index++;
	return (index);
}
