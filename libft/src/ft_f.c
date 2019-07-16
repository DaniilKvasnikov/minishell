/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:20:28 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 17:53:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static double	ft_dop(double n)
{
	unsigned long long c;

	c = n;
	n -= c;
	return (n);
}

static char		*ft_dtoa(long double n)
{
	char	*str;
	char	*dop;
	char	*res;
	int		i;

	str = ft_itoa(n / 1);
	n = n * (n >= 0) + (-n) * (n < 0);
	dop = ft_strnew(7);
	dop[0] = '.';
	i = 0;
	n = ft_dop(n);
	while (++i < 7)
	{
		n *= 10.0 + 1e-9;
		dop[i] = (int)n + '0';
		while (n >= 1)
			n -= 1;
	}
	res = ft_strnew(ft_strlen(str) + ft_strlen(dop));
	ft_strcpy(res, str);
	ft_strcpy(res + ft_strlen(str), dop);
	free(str);
	free(dop);
	return (res);
}

int				ft_f(t_spec *elem, va_list ap)
{
	char	*str;
	int		size;

	if (elem->character == 'F')
		elem->character = 'f';
	if (elem->length == 8)
		str = ft_dtoa(va_arg(ap, long double));
	else
		str = ft_dtoa(va_arg(ap, double));
	size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
