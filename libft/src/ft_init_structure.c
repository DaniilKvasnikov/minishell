/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:30:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:54:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	return (-1);
}

int		is_character(t_spec *elem, char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '%')
		return (elem->character = c);
	elem->character = 0;
	return (0);
}

char	*get_character(t_spec *elem, char *str)
{
	int	index;

	index = 0;
	if (is_character(elem, str[index]) != 0)
		index++;
	return (&(str[index]));
}

int		ft_init_structure(t_spec *elem, char *str)
{
	char *start;

	start = str;
	ft_clear_structure(elem);
	str++;
	str = get_flags(elem, str);
	str = get_width(elem, str);
	str = get_precision(elem, str);
	str += get_length(elem, str);
	str = get_character(elem, str);
	return (str - start);
}
