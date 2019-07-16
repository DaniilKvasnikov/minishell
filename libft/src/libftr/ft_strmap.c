/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:46:50 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 12:46:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		res[index] = (*f)(s[index]);
		index++;
	}
	return (res);
}
