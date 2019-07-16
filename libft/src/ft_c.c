/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:39:23 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 16:11:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_c(t_spec *elem, va_list ap)
{
	int		size;
	int		c;

	c = (int)va_arg(ap, int);
	if (elem->character == 'c' && elem->length != 3)
		c = (char)c;
	size = 1 + (c >= 0x00000080) + (c >= 0x00000800);
	while (size < elem->width && !elem->flag.minus)
	{
		size++;
		if (!elem->flag.zerro)
			ft_putchar(' ');
		else
			ft_putchar('0');
	}
	ft_putchar(c);
	while (size < elem->width && elem->flag.minus)
	{
		size++;
		ft_putchar(' ');
	}
	return (size);
}
