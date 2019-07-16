/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:42:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/01/30 21:43:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	*line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strdup(buf);
		return (1);
	}
	return (ret);
}

void	vect_push(t_vect *vect, char *str)
{
	char	*new;
	size_t	size;

	if (str == NULL)
		return ;
	if (vect->content == NULL)
	{
		if ((vect->content = ft_strdup(str)) == NULL)
			return ;
		vect->size = ft_strlen(str);
	}
	else if (vect->size <
			(size = ft_strlen(vect->content) + ft_strlen(str) + 1))
	{
		while (vect->size < size)
			vect->size *= 2;
		new = ft_strnew(vect->size);
		ft_strcat(new, vect->content);
		ft_strcat(new, str);
		free(vect->content);
		vect->content = new;
	}
	else
		ft_strcat(vect->content, str);
	free(str);
}

void	vect_move(t_vect *vect)
{
	size_t	size;
	char	*ch;
	char	*str;
	size_t	index;

	ch = ft_strchr(vect->content, '\n');
	size = ch - (char *)(vect->content) + 1;
	index = 0;
	str = vect->content;
	while (str[index + size])
	{
		str[index] = str[index + size];
		index++;
	}
	while (str[index])
		str[index++] = '\0';
}

char	*vect_pull(t_vect *vect)
{
	char	*ch;
	char	*res;
	size_t	size;

	if (vect->content == NULL || (ch = ft_strchr(vect->content, '\n')) == NULL)
		return (NULL);
	size = ch - (char *)(vect->content);
	res = ft_memalloc(size + 1);
	ft_memcpy(res, vect->content, size);
	vect_move(vect);
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char			*str;
	static t_vect	vect[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || line == NULL ||
		read(fd, NULL, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((*line = vect_pull(&(vect[fd]))) == NULL)
	{
		if (get_line(fd, &str) == 0)
			break ;
		vect_push(&(vect[fd]), str);
	}
	if (*line == NULL)
	{
		if (vect[fd].content == NULL)
			return (0);
		if (ft_strlen(vect[fd].content) <= 0)
		{
			ft_memdel(&(vect[fd].content));
			return (0);
		}
		*line = ft_strdup(vect[fd].content);
		ft_memdel(&(vect[fd].content));
	}
	return (1);
}
