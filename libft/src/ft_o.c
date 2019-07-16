/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:43:52 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 17:54:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static unsigned long long int	allocator(t_spec *elem,
								unsigned long long int n)
{
	if (elem->length == 3 || elem->character == 'O')
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

int								ft_o(t_spec *elem, va_list ap)
{
	unsigned long long int	num;
	char					*par;
	int						size;

	num = allocator(elem, va_arg(ap, unsigned long long int));
	if ((par = ft_rebase(num, 8)) == NULL)
		return (-1);
	if (elem->flag.sharp && elem->precision > 1)
		elem->precision--;
	if (elem->precision != -1 && num == 0 && elem->flag.sharp == 0)
		return (ft_output(elem, "", 0));
	if (elem->precision != -1 && elem->flag.sharp == 1)
		elem->flag.sharp = (num != 0);
	if (num == 0 && elem->flag.sharp == 1)
		elem->flag.sharp = 0;
	if (elem->flag.sharp == 1)
		size = ft_output(elem, par, ft_strlen(par) + 1);
	else
		size = ft_output(elem, par, ft_strlen(par));
	free(par);
	return (size);
}
