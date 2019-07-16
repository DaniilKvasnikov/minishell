/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:08:11 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 14:08:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*st;
	char	*fi;
	char	*res;
	int		index;

	if (s == NULL)
		return (NULL);
	st = (char *)s;
	fi = (char *)(s + ft_strlen(s) - 1);
	while (fi >= st && ft_space(*fi))
		fi--;
	while (st <= fi && ft_space(*st))
		st++;
	res = ft_strnew(fi - st + 1);
	if (res == NULL)
		return (NULL);
	index = 0;
	while (st <= fi)
	{
		res[index] = *st;
		index++;
		st++;
	}
	res[index] = '\0';
	return (res);
}
