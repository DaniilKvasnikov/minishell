/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:51:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/19 18:51:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (((unsigned char)*s1) - ((unsigned char)*s2));
		s1++;
		s2++;
	}
	if (*s1 != '\0')
		return (((unsigned char)*s1));
	else if (*s2 != '\0')
		return (-(((unsigned char)*s2)));
	return (0);
}
