/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:52:43 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/15 18:43:56 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;
	int		chr;

	if (!line || fd < 0 || read(fd, buffer, 0))
		return (-1);
	while ((chr = ft_strchr(buf, '\n')) 
			&& (ret = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if (!(buf = ft_strjoin(buf, buffer)))
			return (-1);
	}
	if (chr > 0)
	{
		*line = ft_substr(buf, 0, chr);
		buf = ft_substr(buf, chr + 1, ft_strlen(buf) - chr);
		return (1);
	}
	free(buf);
	buf = ft_strdup("");
	*line = ft_strdup("");
	return (0);
}

int main(int ac, char **av)
{	
	int		fd;
	int		ret;
	char	*d;

	if (ac == 1)
		fd = 1;
	else
		fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &d) == 1))
		printf("%d	%s	%zu\n", ret, d, ft_strlen(d));
	ret = get_next_line(fd, &d);
	printf("%d\n", ret);
	free(d);
	close(fd);
	return 0;
}
