/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:52:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 10:22:47 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_clear_structure_flag(t_spec *elem)
{
	elem->flag.minus = 0;
	elem->flag.plus = 0;
	elem->flag.space = 0;
	elem->flag.zerro = 0;
	elem->flag.sharp = 0;
}

void		ft_clear_structure(t_spec *elem)
{
	ft_clear_structure_flag(elem);
	elem->width = 0;
	elem->length = 0;
	elem->precision = -1;
	elem->character = -1;
}
