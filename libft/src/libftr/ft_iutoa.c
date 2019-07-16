/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:03:05 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/10 01:50:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n)
{
	int		size;

	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_iutoa(unsigned long long n)
{
	char	*res;
	int		index;

	if (n == 0)
		return (ft_strdup("0"));
	res = ft_strnew(get_size(n));
	if (res == NULL)
		return (NULL);
	index = get_size(n);
	res[index] = '\0';
	while (n > 0)
	{
		index--;
		res[index] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
