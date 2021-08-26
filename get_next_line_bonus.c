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

#include "get_next_line.h"

char	*doline(int len, char **str, const int fd, char *line)
{
	char	*tmp;

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

char	*addline(char **str, const int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = NULL;
	if (str[fd] == '\0' || str[fd][len] == '\0')
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}	
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	return (doline(len, str, fd, line));
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
	return (addline(str, fd));
}
