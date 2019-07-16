/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:29:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:33:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_list	ap2;
	int		result;
	t_spec	*spec;

	if ((spec = (t_spec *)malloc(sizeof(t_spec))) == NULL)
		return (-1);
	result = 0;
	va_start(ap, format);
	va_copy(ap2, ap);
	while (*format)
	{
		if (*format == '%')
		{
			format += ft_init_structure(spec, (char *)format);
			result += ft_put_structure(spec, ap) - 1;
		}
		else
			write(1, format++, 1);
		result++;
	}
	va_end(ap);
	va_end(ap2);
	free(spec);
	return (result);
}
