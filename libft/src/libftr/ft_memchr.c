/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:52:12 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/21 19:52:14 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *point;

	point = (unsigned char *)s;
	while (n > 0)
	{
		if (*point == ((unsigned char)c))
			return ((void*)point);
		point++;
		n--;
	}
	return (NULL);
}
