/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:10:59 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 02:11:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*point;
	int		n;

	n = ft_strlen(s) + 1;
	point = (char *)s + n - 1;
	while (n > 0)
	{
		if (*point == ((unsigned char)c))
			return (point);
		point--;
		n--;
	}
	return (NULL);
}
