/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscamand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:24:45 by bscamand          #+#    #+#             */
/*   Updated: 2020/11/12 22:24:46 by bscamand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (char *)(s);
		s++;
	}
	if (*s == c)
		return (char *)(s);
	return (NULL);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*s1n;

	i = 0;
	s1n = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s1n)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1n[i] = s1[i];
		i++;
	}
	s1n[i] = '\0';
	return (s1n);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*cated;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	cated = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cated)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		cated[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		cated[i] = s2[j];
		++i;
		++j;
	}
	cated[i] = '\0';
	return (cated);
}
