/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:07:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 13:07:26 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*res;

	index = 0;
	if (s == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res == NULL)
		return (NULL);
	while (s[index] != '\0')
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	return (res);
}
