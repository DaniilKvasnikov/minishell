/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:46:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/07/26 18:48:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	is_space(char c, char nc)
{
	return (c == nc || (c >= 9 && c <= 13));
}

static int	ft_str_count(char const *s, char c)
{
	int size;

	size = 0;
	while (*s != '\0')
	{
		if (!is_space(*s, c) || (is_space(*(s + 1), c) || *(s + 1) == '\0'))
			size++;
		s++;
	}
	return (size);
}

static char	*get_fi(char *fi, char c)
{
	int	i;

	i = -1;
	while (fi[++i] != '\0' && !is_space(fi[i], c))
	{
		if (fi[i] == '\'')
			while (fi[++i] != '\0' && fi[i] != '\'')
				if (fi[i] == '\"')
					return (NULL);
		if (fi[i] == '\"')
			while (fi[++i] != '\0' && fi[i] != '\"')
				if (fi[i] == '\'')
					return (NULL);
	}
	return (fi + i);
}

static char	*ft_str_get(char const **s, char c)
{
	char	*st;
	char	*fi;
	char	*res;
	int		index;

	st = (char *)*s;
	if ((fi = get_fi((char *)*s, c)) == NULL)
		return (NULL);
	if ((res = ft_strnew(fi - st)) == NULL)
		return (NULL);
	index = -1;
	while (st < fi)
		res[++index] = *st++;
	*s = fi - (*fi == '\0');
	res[++index] = '\0';
	if (res[index - 1] == '\'' || res[index - 1] == '\"')
		res[index - 1] = '\0';
	if (res[0] == '\'' || res[0] == '\"')
	{
		st = res;
		res = ft_strdup(res + 1);
		free(st);
	}
	return (res);
}

char		**ft_strsplit_argv(char const *s, char c)
{
	char	**res;
	int		size;
	int		index;

	if (s == NULL)
		return (NULL);
	size = ft_str_count(s, c);
	if ((res = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	index = -1;
	s--;
	while (*(++s) != '\0')
		if (!is_space(*s, c))
		{
			res[++index] = ft_str_get(&s, c);
			if (res[index] == NULL)
			{
				while (--index >= 0)
					free(res[index]);
				free(res);
				return (NULL);
			}
		}
	res[++index] = NULL;
	return (res);
}
