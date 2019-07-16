/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:57:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 13:57:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, s1, ft_strlen(s1));
	ft_strncpy(res + ft_strlen(s1), s2, ft_strlen(s2));
	free((char *)s1);
	return (res);
}
