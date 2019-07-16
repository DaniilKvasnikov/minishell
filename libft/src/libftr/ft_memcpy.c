/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:12:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/21 17:12:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src_, size_t n)
{
	char	*point;
	char	*src;

	if (n == 0 || (dst == NULL && src_ == NULL))
		return (dst);
	src = (char *)src_;
	point = (char *)dst;
	while (n > 0)
	{
		*point = *(src);
		point++;
		src++;
		n--;
	}
	return (dst);
}
