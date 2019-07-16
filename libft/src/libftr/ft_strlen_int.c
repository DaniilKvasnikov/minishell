/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:24:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/12 21:47:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_int(int *str)
{
	size_t len;
	size_t size;

	len = 0;
	size = 0;
	while (str[len] != '\0')
	{
		if (str[len] < 0x80)
			size++;
		else
		{
			if (str[len] >= 0x00000800)
				size += 3;
			else if (str[len] >= 0x00000080)
				size += 2;
		}
		len++;
	}
	return (size);
}
