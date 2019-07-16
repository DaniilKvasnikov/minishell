/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:15:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/21 19:15:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (src < dst)
		while ((int)(--len) >= 0)
		{
			pdst[len] = psrc[len];
		}
	else
		while ((int)(--len) >= 0)
		{
			*pdst = *psrc;
			pdst++;
			psrc++;
		}
	return (dst);
}
