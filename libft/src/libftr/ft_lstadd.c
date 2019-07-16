/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:33:21 by rrhaenys          #+#    #+#             */
/*   Updated: 2018/11/23 23:33:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *news)
{
	if (alst == NULL || news == NULL)
		return ;
	if (*alst != NULL)
		news->next = (*alst);
	*alst = news;
}
