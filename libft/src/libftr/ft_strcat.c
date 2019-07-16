/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 00:16:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 00:16:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *point;

	point = s1;
	while (*point != '\0')
		point++;
	while (*s2 != '\0')
	{
		*point = *s2;
		s2++;
		point++;
	}
	*point = '\0';
	return (s1);
}
