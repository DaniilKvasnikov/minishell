/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:29:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/23 13:29:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c)
{
	int size;

	size = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			size++;
		s++;
	}
	return (size);
}

static char	*ft_str_get(char const **s, char c)
{
	char	*st;
	char	*fi;
	char	*res;
	int		index;

	st = (char *)*s;
	fi = (char *)*s;
	while (*fi != c && *fi != '\0')
		fi++;
	res = ft_strnew(fi - st);
	if (res == NULL)
		return (NULL);
	index = 0;
	while (st < fi)
	{
		res[index] = *st;
		index++;
		st++;
	}
	*s = fi - (*fi == '\0');
	res[index] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		size;
	int		index;

	if (s == NULL)
		return (NULL);
	size = ft_str_count(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (NULL);
	index = 0;
	s--;
	while (*(++s) != '\0')
		if (*s != c)
		{
			res[index] = ft_str_get(&s, c);
			if (res[index] == NULL)
				return (NULL);
			index++;
		}
	res[index] = NULL;
	return (res);
}
