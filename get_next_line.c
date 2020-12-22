/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/22 16:24:13 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

static int	get_line(char **buf, char **line)
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
	static char	*buf;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	int			chr;

	if (!line || fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	while (((chr = ft_strchr(buf, '\n')) == -1)
			&& (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(buf = ft_strjoin(buf, buffer)))
			return (-1);
	}
	if (chr > -1)
	{
		*line = ft_substr(buf, 0, chr, 0);
		buf = ft_substr(buf, chr + 1, ft_strlen(buf) - chr, 1);
		return (1);
	}
	if (!get_line(&buf, line))
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		i = 0;
	char	*d;

	if (ac == 1)
		fd = 1;
	else
		fd = open(av[1], O_RDONLY);
	while (i < BUFFER_SIZE)
	{
		ret = get_next_line(fd, &d);
		printf("%d	%s	%zu\n", ret, d, ft_strlen(d));
		i++;
	}
	free(d);
	close(fd);
	return 0;
}
