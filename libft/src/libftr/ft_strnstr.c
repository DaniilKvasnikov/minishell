/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:57:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 02:57:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find(const char *haystack, const char *needle,
				size_t *p1, size_t *p2)
{
	while (needle[*p2] != '\0')
	{
		if (haystack[*p1] != needle[*p2])
			break ;
		(*p2)++;
		(*p1)++;
	}
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	p1;
	size_t	p2;
	size_t	temp;

	if (haystack == needle || ft_strlen(needle) == 0)
		return ((char *)haystack);
	p1 = -1;
	while (haystack[++p1] != '\0')
	{
		temp = p1;
		p2 = 0;
		if (haystack[p1] == needle[p2])
		{
			find(haystack, needle, &p1, &p2);
			if (needle[p2] == '\0' && p1 <= len)
				return ((char *)&(haystack[temp]));
		}
		p1 = temp;
	}
	return (NULL);
}
