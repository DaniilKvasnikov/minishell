/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:55:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/21 17:55:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *point;

	point = (unsigned char *)dst;
	while (n > 0)
	{
		*point = *((char *)src);
		if (*point == ((unsigned char)c))
			return (++point);
		point++;
		src++;
		n--;
	}
	return (NULL);
}
