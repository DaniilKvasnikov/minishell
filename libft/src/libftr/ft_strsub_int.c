/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:33:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/12 19:33:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_strsub_int(int *s, unsigned int start, size_t len)
{
	int *res;

	if (s == NULL)
		return (NULL);
	res = ft_strnew_int(len);
	if (res == NULL)
		return (NULL);
	res = ft_strncpy_int(res, s + start, len);
	return (res);
}
