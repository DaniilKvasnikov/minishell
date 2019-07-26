/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:45:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:45:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void
	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		put_start_shell(NULL);
	}
}
