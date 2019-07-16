/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:25:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/12 19:29:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_strncpy_int(int *dst, const int *src, size_t len)
{
	int *point;

	point = dst;
	while (len > 0 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (point);
}
