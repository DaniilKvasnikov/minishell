/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:43:59 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/23 23:44:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*my_stmap(t_list *lst, t_list *(*f)(t_list *e), t_list *res)
{
	t_list *res_index;
	t_list *new;

	while (lst != NULL && f != NULL)
	{
		if ((new = f(lst)) != NULL)
		{
			if ((new = ft_lstnew(new->content, new->content_size)) == NULL)
				return (NULL);
			if (res == NULL)
			{
				res = new;
				res_index = res;
			}
			else
			{
				res_index->next = new;
				res_index = res_index->next;
			}
		}
		lst = lst->next;
	}
	return (res);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst != NULL && f != NULL)
		return (my_stmap(lst, f, NULL));
	return (lst);
}
