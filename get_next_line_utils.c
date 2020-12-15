/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:52:42 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/15 18:42:14 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *s, int c)
{
	unsigned char	*ss;
	int				i;

	i = 0;
	ss = (unsigned char *)s;
	if (!s || !ss)
		return (-1);
	while ((ss[i] != c) && (s[i] != '\0'))
		i++;
	if (ss[i] == c)
		return (i);
	return (0);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(char	const *s, size_t start, size_t len)
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
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;

	if (!s2 || !(new_s = malloc(sizeof(new_s) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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
		new_s[j + i] = s2[j];
		j++;
	}
	new_s[j + i] = '\0';
	return (new_s);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	if (!(s = malloc(sizeof(char) * len)))
		return (NULL);
	while (len-- && (*s1 != '\0'))
		*s++ = *s1++;
	*s = '\0';
	return (s);
}
