/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:58:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:25:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_rgyles.h"
#include "ft_array.h"

static void	ft_get_wid_prec(t_spec *elem, va_list ap)
{
	if (elem->width == -2)
	{
		elem->width = (int)va_arg(ap, int);
		if (elem->width < 0)
		{
			elem->width *= -1;
			elem->flag.minus = 1;
		}
	}
	if (elem->precision == -2)
	{
		elem->precision = (int)va_arg(ap, int);
		if (elem->precision < 0)
			elem->precision = -1;
	}
}

int			ft_put_structure(t_spec *elem, va_list ap)
{
	int	index;

	ft_get_wid_prec(elem, ap);
	index = -1;
	while (g_funs[++index].f != NULL)
	{
		if (g_funs[index].c == elem->character)
			return (g_funs[index].f(elem, ap));
	}
	return (ft_invalid_character(elem));
}
