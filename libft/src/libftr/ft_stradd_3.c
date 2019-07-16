/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:17:56 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:18:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_stradd_3(char *s1, char *s2, char *s3)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_bzero(res, ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	ft_strcat(res, s1);
	ft_strcat(res, s2);
	ft_strcat(res, s3);
	return (res);
}
