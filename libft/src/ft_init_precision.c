/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:18:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 17:36:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_wid_prec(t_spec *elem, char *str)
{
	int	index;

	index = 1;
	if (str[index - 1] != '.')
	{
		elem->precision = -1;
		return (&(str[0]));
	}
	if (str[index] == '*')
	{
		elem->precision = -2;
		return ((str + 2));
	}
	return (NULL);
}

char		*get_precision(t_spec *elem, char *str)
{
	int	index;
	int	sum;
	int num;

	index = 1;
	sum = 0;
	if (ft_get_wid_prec(elem, str) != NULL)
		return (ft_get_wid_prec(elem, str));
	while ((num = is_num(str[index])) >= 0)
	{
		sum = sum * 10 + num;
		if (sum < 0)
		{
			sum = -1;
			break ;
		}
		index++;
	}
	while ((num = is_num(str[index])) >= 0)
		index++;
	elem->precision = sum;
	return (&(str[index]));
}
