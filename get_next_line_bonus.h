/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:58:51 by jzeybel           #+#    #+#             */
/*   Updated: 2020/12/22 21:34:43 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char const *s);
int		ft_strchr(char *s, int c);
char	*ft_substr(char *s, size_t start, size_t len, int tofree);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s1);
#endif
