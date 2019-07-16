/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:16:11 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 00:16:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *point;

	point = s1;
	while (*point != '\0')
		point++;
	while (n > 0 && *s2 != '\0')
	{
		*point = *s2;
		s2++;
		point++;
		n--;
	}
	*point = '\0';
	return (s1);
}
