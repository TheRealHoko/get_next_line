/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/06 16:32:59 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char **buf, char **line)
{
	if (*buf)
		*line = *buf;
	else
	{
		*line = malloc(sizeof(char) * 1);
		if (!*line)
			return (0);
		*line[0] = '\0';
	}
	*buf = NULL;
	return (1);
}

int	retline(int chr, char **buf, char **line)
{
	*line = ft_substr(*buf, 0, chr, 0);
	if (!*line)
		return (0);
	*buf = ft_substr(*buf, chr + 1, ft_strlen(*buf) - chr, 1);
	if (!*buf)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[FD];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			chr;

	ret = 1;
	if (!line || fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	chr = ft_strchr(buf[fd], '\n');
	while ((chr == -1) && (ret))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		buf[fd] = ft_strjoin(buf[fd], buffer);
		if (!buf[fd])
			return (-1);
		chr = ft_strchr(buf[fd], '\n');
	}
	if (chr > -1)
		return (retline(chr, &buf[fd], line));
	if (!get_line(&buf[fd], line))
		return (-1);
	return (0);
}
