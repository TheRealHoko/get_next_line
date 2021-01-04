/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2021/01/04 14:41:15 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line(char **buf, char **line)
{
	if (*buf)
	{
		*line = *buf;
	}
	else
	{
		*line = ft_strdup("");
		*line[0] = '\0';
	}
	*buf = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[FD];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			chr;

	if (!line || fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	while (((chr = ft_strchr(buf[fd], '\n')) == -1)
			&& (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(buf[fd] = ft_strjoin(buf[fd], buffer)))
			return (-1);
	}
	if (chr > -1)
	{
		*line = ft_substr(buf[fd], 0, chr, 0);
		buf[fd] = ft_substr(buf[fd], chr + 1, ft_strlen(buf[fd]) - chr, 1);
		return (1);
	}
	if (!get_line(&buf[fd], line))
		return (-1);
	return (0);
}
