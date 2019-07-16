/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:35:03 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:54:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static void	put_space(int *size, char c)
{
	(*size)++;
	ft_putchar(c);
}

int			ft_output_int(t_spec *elem, int *str, int size)
{
	while (size < elem->width && !elem->flag.minus && !elem->flag.zerro)
		put_space(&size, ' ');
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
		put_space(&size, '0');
	ft_putstr_int(str);
	while (size < elem->width && elem->flag.minus)
		put_space(&size, ' ');
	return (size);
}
