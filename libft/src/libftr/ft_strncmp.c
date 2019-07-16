/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 03:05:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 03:05:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1) - ((unsigned char)*s2));
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else if (*s1 != '\0')
		return (((unsigned char)*s1));
	else if (*s2 != '\0')
		return (-(((unsigned char)*s2)));
	return (0);
}
