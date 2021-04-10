/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscamand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:25:01 by bscamand          #+#    #+#             */
/*   Updated: 2020/11/12 22:25:02 by bscamand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 2

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);

#endif
