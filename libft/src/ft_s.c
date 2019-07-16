/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:29:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:29:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

int		ft_sbig(t_spec *elem, va_list ap)
{
	int		size;
	int		*str;

	size = 0;
	str = (int *)va_arg(ap, int*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (elem->precision != -1)
	{
		str = ft_strsub_int(str, 0, elem->precision);
		size = ft_strlen_int(str);
		size = ft_output_int(elem, str, size);
		free(str);
	}
	else
	{
		size = ft_strlen_int(str);
		size = ft_output_int(elem, str, size);
	}
	return (size);
}

int		ft_s(t_spec *elem, va_list ap)
{
	int		size;
	char	*str;

	if (elem->length == 3)
		return (ft_sbig(elem, ap));
	size = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
	{
		if (elem->flag.zerro == 0)
		{
			ft_putstr("(null)");
			return (6);
		}
		else
			str = "";
	}
	if (elem->precision != -1 && elem->precision < (int)ft_strlen(str))
	{
		str = ft_strsub(str, 0, elem->precision);
		size = ft_output(elem, str, ft_strlen(str));
		free(str);
		return (size);
	}
	return (ft_output(elem, str, ft_strlen(str)));
}
