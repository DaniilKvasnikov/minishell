/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:00:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 02:00:26 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	s1l;
	size_t	s2l;
	size_t	index;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (n < s1l + 1)
		return (s2l + n);
	if (n > s1l + 1)
	{
		index = s1l;
		while (index < n - 1 && *s2 != '\0')
		{
			*(s1 + index++) = *s2;
			s2++;
		}
		*(s1 + index) = '\0';
	}
	return (s1l + s2l);
}
