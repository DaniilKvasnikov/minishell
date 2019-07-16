/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:05:14 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/14 10:22:57 by rgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPEC_H
# define FT_SPEC_H

typedef struct	s_flag
{
	char		minus;
	char		plus;
	char		space;
	char		zerro;
	char		sharp;
}				t_flag;

typedef struct	s_spec
{
	t_flag		flag;
	int			width;
	int			precision;
	int			length;
	char		character;
}				t_spec;

#endif
