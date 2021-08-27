/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:34:56 by acastril          #+#    #+#             */
/*   Updated: 2021/08/19 16:32:28 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int	c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	size_t			i;
	unsigned char	*temp;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	temp = mem;
	i = 0;
	while (i++ < size * count)
		*temp++ = 0;
	return (mem);
}

char	*doline(int len, char **str, const int fd)
{
	char	*tmp;
	char	*line;

	line = NULL;
	if (str[fd][len] == '\n')
	{
		line = ft_substr(str[fd], 0, len + 1);
		tmp = ft_strdup(&(str[fd][len + 1]));
		free(str[fd]);
		str[fd] = tmp;
	}
	else
	{
		line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (line);
}

char	*output(char **str, const int fd)
{
	int		len;

	len = 0;
	if (str[fd] == '\0' || str[fd][len] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}	
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	return (doline(len, str, fd));
}

char	*get_next_line(const int fd)
{
	static char	*str[FILE_N];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	size_t		chars;

	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	chars = read(fd, buff, BUFFER_SIZE);
	while (chars)
	{	
		buff[chars] = '\0';
		if (!str[fd])
			str[fd] = ft_calloc(sizeof(char), BUFFER_SIZE);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		chars = read(fd, buff, BUFFER_SIZE);
	}
	return (output(str, fd));
}
