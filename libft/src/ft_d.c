/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:19:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:54:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static char	*allocator(t_spec *elem, long long int n)
{
	if (elem->length == 3)
		return (ft_itoa_lli((long int)n, elem));
	else if (elem->length == 6)
		return (ft_itoa_lli((ssize_t)n, elem));
	else if (elem->length == 5)
		return (ft_itoa_lli((intmax_t)n, elem));
	else if (elem->length == 1)
		return (ft_itoa_lli((short int)n, elem));
	else if (elem->length == 2)
		return (ft_itoa_lli((signed char)n, elem));
	else if (elem->length == 4)
		return (ft_itoa_lli(n, elem));
	else
		return (ft_itoa_lli((int)n, elem));
}

int			ft_d(t_spec *elem, va_list ap)
{
	int				size;
	char			*str;

	if (elem->character == 'D')
		str = ft_itoa_lli(va_arg(ap, long long int), elem);
	else
		str = allocator(elem, va_arg(ap, long long int));
	if (elem->character == 'D' || elem->character == 'i')
		elem->character = 'd';
	if (elem->precision > 0)
		elem->flag.zerro = 0;
	if (str[0] == '0' && elem->precision == 0)
		size = ft_output(elem, "\0", 0);
	else if (elem->flag.plus != 0 || elem->flag.space != 0)
		size = ft_output(elem, str, ft_strlen(str) + 1);
	else
		size = ft_output(elem, str, ft_strlen(str));
	free(str);
	return (size);
}
