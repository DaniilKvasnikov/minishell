/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 19:07:48 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 17:54:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rgyles.h"

static void	put_space(int *size, char c)
{
	(*size)++;
	ft_putchar(c);
}

static void	flag_check(t_spec *elem)
{
	if (elem->flag.plus == 1)
		ft_putchar('+');
	else if (elem->flag.plus == 2)
		ft_putchar('-');
	else if (elem->flag.space == 1)
		ft_putchar(' ');
}

static char	*precision_check(char *str, t_spec *elem)
{
	int		i;
	int		size;
	char	*str_pre;
	char	*newstr;

	size = elem->precision;
	if (elem->character == 'f')
	{
		size += ft_strchr(str, '.') - str + 1;
		newstr = ft_strnew(size);
		str_pre = ft_memset(newstr, '0', size);
		i = -1;
		while (++i < size && str[i] != '\0')
			str_pre[i] = str[i];
	}
	else
	{
		i = ft_strlen(str);
		newstr = ft_strnew(size);
		str_pre = ft_memset(newstr, '0', size);
		while (size >= 0 && i >= 0)
			str_pre[size--] = str[i--];
	}
	free(newstr);
	return (str_pre);
}

static void	sharp_check(t_spec *elem)
{
	if (elem->character == 'p' || elem->character == 'x')
		ft_putstr("0x");
	else if (elem->character == 'X')
		ft_putstr("0X");
	else if (elem->character == 'o' || elem->character == 'O')
		ft_putchar('0');
}

int			ft_output(t_spec *elem, char *str, int size)
{
	if (elem->precision > 0 && (elem->character == 'f'
		|| (elem->precision > (int)ft_strlen(str) &&
		elem->character != '%' && elem->character != 's')))
	{
		size += elem->precision - (int)ft_strlen(str);
		str = precision_check(str, elem);
	}
	while (size < elem->width && !elem->flag.minus && !elem->flag.zerro)
		put_space(&size, ' ');
	if (elem->flag.sharp == 1)
		sharp_check(elem);
	if (elem->character == 'd')
		flag_check(elem);
	while (size < elem->width && !elem->flag.minus && elem->flag.zerro)
		put_space(&size, '0');
	if (elem->character == 'X')
		ft_toupper_str(str);
	ft_putstr(str);
	while (size < elem->width && elem->flag.minus)
		put_space(&size, ' ');
	return (size);
}
