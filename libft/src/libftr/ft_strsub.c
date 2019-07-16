/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:35:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/22 13:35:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	if (s == NULL)
		return (NULL);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	res = ft_strncpy(res, s + start, len);
	return (res);
}
