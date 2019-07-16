/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:07:37 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 15:26:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "ft_printf.h"

const t_func	g_funs[] = {
	{'C', &ft_c},
	{'c', &ft_c},
	{'d', &ft_d},
	{'D', &ft_d},
	{'u', &ft_u},
	{'U', &ft_u},
	{'i', &ft_d},
	{'s', &ft_s},
	{'S', &ft_sbig},
	{'p', &ft_p},
	{'x', &ft_x},
	{'X', &ft_x},
	{'%', &ft_percent},
	{'o', &ft_o},
	{'O', &ft_o},
	{'f', &ft_f},
	{'F', &ft_f},
	{'0', NULL}};

#endif
