/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscamand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:24:05 by bscamand          #+#    #+#             */
/*   Updated: 2020/11/12 22:24:08 by bscamand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strnew(int size)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}

static void			ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

static char			*check_last(char **last, char **line)
{
	char			*ptr;

	ptr = NULL;
	*line = NULL;
	if (*last != NULL)
	{
		if ((ptr = ft_strchr(*last, '\n')))
		{
			*ptr = '\0';
			ptr++;
			*line = ft_strdup(*last);
			if (*ptr)
				ft_strcpy(*last, ptr);
			else
				ft_strclr(&*last);
		}
		else
		{
			*line = ft_strdup(*last);
			ft_strclr(&*last);
		}
	}
	else
		*line = ft_strnew(0);
	return (ptr);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	char			*ptr;
	int				n;
	static char		*last[1024];

	if (!line || fd > 1023 || BUFFER_SIZE < 1 ||
		!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) ||
		(read(fd, buf, 0)) < 0)
		return (-1);
	ptr = check_last(&last[fd], line);
	while ((!ptr) && (n = read(fd, buf, BUFFER_SIZE)))
	{
		buf[n] = '\0';
		if ((ptr = ft_strchr(buf, '\n')))
		{
			*ptr = '\0';
			ptr++;
			if ((*ptr) && !(last[fd] = ft_strdup(ptr)))
				return (-1);
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	free(buf);
	return (ptr ? 1 : 0);
}
