/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:36:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 19:03:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_auto.h"

char
	**character_name_completion(const char *text, int start, int end)
{
	rl_attempted_completion_over = 1;
	return (rl_completion_matches(text, character_name_generator));
	start = 0;
	end = 0;
}

char
	*character_name_generator(const char *text, int state)
{
	static int	list_index;
	static int	len;
	char		*name;

	if (!state)
	{
		list_index = 0;
		len = ft_strlen(text);
	}
	while ((name = g_character_names[list_index++]))
		if (ft_strncmp(name, text, len) == 0)
			return (ft_strdup(name));
	return (NULL);
}
