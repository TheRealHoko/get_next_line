/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:52:42 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/22 16:20:25 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, size_t start, size_t len, int tofree)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	maxlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	maxlen = start;
	i = 0;
	while (s[maxlen++] != '\0' && i < len)
		i++;
	if (!(new_s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		new_s[i] = s[start++];
		i++;
	}
	new_s[i] = '\0';
	if (tofree == 1)
		free(s);
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	if (!(new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_s[i + j] = s2[j];
		j++;
	}
	new_s[i + j] = '\0';
	if (s1)
		free(s1);
	return (new_s);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- && (*s1 != '\0'))
		*s++ = *s1++;
	*s = '\0';
	return (s);
}