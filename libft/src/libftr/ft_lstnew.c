/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:56:46 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/23 22:56:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *obj;

	obj = (t_list *)ft_memalloc(sizeof(t_list));
	if (obj == NULL)
		return (NULL);
	if (content == NULL)
	{
		obj->content = NULL;
		obj->content_size = 0;
	}
	else
	{
		obj->content = ft_memalloc(content_size);
		if (obj->content == NULL)
		{
			free(obj);
			return (NULL);
		}
		obj->content = ft_memcpy(obj->content, content, content_size);
		obj->content_size = content_size;
	}
	obj->next = NULL;
	return (obj);
}
