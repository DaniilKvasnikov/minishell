/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:49:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/20 16:49:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*pointer;
	size_t			index;

	if (n == 0)
		return (str);
	index = n;
	pointer = (unsigned char *)str;
	while (index > 0)
	{
		*pointer = (unsigned char)c;
		pointer++;
		index--;
	}
	return (str);
}
