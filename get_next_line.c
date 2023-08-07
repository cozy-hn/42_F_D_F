/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiko <jiko@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:26:01 by jiko              #+#    #+#             */
/*   Updated: 2023/08/07 21:28:10 by jiko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *s1, char *s2, int flag)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (flag)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	dest = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (freeing(0, s1, NULL));
	while (s1[++i])
		dest[i] = s1[i];
	free(s1);
	while (s2[j])
		dest[i++] = s2[j++];
	return (dest);
}

char	*ft_get_line(char **str, int *i)
{
	char	*dest;

	*i = 0;
	while ((*str)[*i] && (*str)[*i] != '\n')
		(*i)++;
	if ((*str)[*i] == '\0')
	{
		dest = ft_strjoin(0, (*str), 1);
		if (!dest)
			return (NULL);
		return (dest);
	}
	dest = (char *)ft_calloc(*i + 2, sizeof(char));
	if (!dest)
		return (NULL);
	*i = 0;
	while ((*str)[*i] != '\n')
		dest[(*i)++] = (*str)[*i];
	dest[(*i)++] = '\n';
	return (dest);
}

char	*freeing(char **str, char *buf, char *dest)
{
	if (buf)
		free(buf);
	if (dest)
		free(dest);
	if (!str)
		return (0);
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (NULL);
}

int	readline(int fd, int *i, char **str)
{
	char	*buf;

	*i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((int)freeing(str, NULL, NULL));
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return ((int)freeing(str, NULL, NULL));
	while (*i > 0)
	{
		if (ft_strchr(*str, '\n'))
			break ;
		*i = read(fd, buf, BUFFER_SIZE);
		if ((!(*str) && *i == 0) || *i < 0)
			return ((int)freeing(str, buf, NULL));
		buf[*i] = '\0';
		*str = ft_strjoin(*str, buf, !(*str));
		if (!(*str))
			return ((int)freeing(0, buf, NULL));
	}
	freeing(&buf, NULL, NULL);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*dest;
	int			i;
	int			flag;

	buf = NULL;
	flag = readline(fd, &i, &str);
	if (!flag)
		return (NULL);
	dest = ft_get_line(&str, &i);
	if (dest && (ft_strlen(str) != ft_strlen(dest)))
	{
		buf = ft_strjoin(NULL, str + i, 1);
		if (!buf)
			return (freeing(&str, NULL, dest));
	}
	free(str);
	str = buf;
	return (dest);
}
