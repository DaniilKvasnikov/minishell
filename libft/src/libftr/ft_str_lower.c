/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:31:49 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/07 20:32:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_str_tolower(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
		str[i] = ft_tolower(str[i]);
	return (str);
}
