/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:14:57 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/20 20:14:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*pointer;

	if (n == 0)
		return ;
	pointer = (unsigned char *)str;
	while (n > 0)
	{
		*pointer = '\0';
		pointer++;
		n--;
	}
}
