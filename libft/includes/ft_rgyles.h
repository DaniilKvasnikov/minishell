/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgyles.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:10:10 by rgyles            #+#    #+#             */
/*   Updated: 2019/01/14 15:28:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RGYLES_H
# define FT_RGYLES_H

# include <stdarg.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_spec.h"
# include "libft.h"
# include <inttypes.h>

typedef struct	s_func
{
	char	c;
	int		(*f)(t_spec *elem, va_list ap);
}				t_func;

int				ft_c(t_spec *elem, va_list ap);
int				ft_o(t_spec *elem, va_list ap);
int				ft_d(t_spec *elem, va_list ap);
int				ft_i(t_spec *elem, va_list ap);
int				ft_u(t_spec *elem, va_list ap);
int				ft_s(t_spec *elem, va_list ap);
int				ft_sbig(t_spec *elem, va_list ap);
int				ft_p(t_spec *elem, va_list ap);
int				ft_x(t_spec *elem, va_list ap);
int				ft_percent(t_spec *elem, va_list ap);
int				ft_f(t_spec *elem, va_list ap);
int				ft_output(t_spec *elem, char *str, int size);
int				ft_output_int(t_spec *elem, int *str, int size);
char			*ft_x_minus(char *str);
char			*ft_precision(char *str, int size);
char			*ft_itoa_ui(unsigned long long int n);
char			*ft_itoa_lli(long long int n, t_spec *elem);
int				ft_invalid_character(t_spec *elem);

#endif
