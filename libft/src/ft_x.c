/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:09:12 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 17:54:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static long long int	allocator(t_spec *elem, unsigned long long int n)
{
	if (elem->length == 3)
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

int						ft_x(t_spec *elem, va_list ap)
{
	int						size;
	char					*str;
	unsigned long long int	n;

	n = allocator(elem, va_arg(ap, unsigned long long int));
	if (n == 0)
	{
		elem->flag.sharp = 0;
		elem->character = 'x';
		if (elem->precision != -1)
			size = ft_output(elem, "", 0);
		else
			size = ft_output(elem, "0", 1);
	}
	else
	{
		if ((str = ft_rebase(n, 16)) == NULL)
			return (-1);
		if (elem->flag.sharp == 1)
			size = ft_output(elem, str, ft_strlen(str) + 2);
		else
			size = ft_output(elem, str, ft_strlen(str));
		free(str);
	}
	return (size);
}
