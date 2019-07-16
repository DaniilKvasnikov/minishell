/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:17:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 16:37:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_width(t_spec *elem, char *str)
{
	int	index;
	int	sum;
	int num;

	index = 0;
	sum = 0;
	if (*str == '*')
	{
		elem->width = -2;
		return ((str + 1));
	}
	while ((num = is_num(str[index])) >= 0)
	{
		sum = sum * 10 + num;
		if (sum < 0)
		{
			sum = 0;
			break ;
		}
		index++;
	}
	while ((num = is_num(str[index])) >= 0)
		index++;
	elem->width = sum;
	return (&(str[index]));
}
