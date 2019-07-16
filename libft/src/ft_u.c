/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:08:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 17:29:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static unsigned long long int	allocator(t_spec *elem,
								unsigned long long int n)
{
	if (elem->length == 3 || elem->character == 'U')
		return ((unsigned long int)n);
	else if (elem->length == 6)
		return ((size_t)n);
	else if (elem->length == 5)
		return ((uintmax_t)n);
	else if (elem->length == 1)
		return ((unsigned short int)n);
	else if (elem->length == 2)
		return ((unsigned char)n);
	else if (elem->length == 4)
		return (n);
	else
		return ((unsigned int)n);
}

int								ft_u(t_spec *elem, va_list ap)
{
	int						size;
	char					*str;
	unsigned long long int	n;

	n = allocator(elem, va_arg(ap, unsigned long long int));
	if (n == 0 && elem->precision != -1)
		size = ft_output(elem, "\0", 0);
	else
	{
		str = ft_itoa_ui(n);
		size = ft_output(elem, str, ft_strlen(str));
		free(str);
	}
	return (size);
}
