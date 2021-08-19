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

void	ft_fdlinedel(char	**str, const int fd)
{
	if (str[fd])
	{
		free(str[fd]);
		str[fd] = NULL;
	}
}

char	*addline(char **str, const int fd)
{
	int		len;
	char	*tmp;
	char	*line;

	len = 0;
	line = NULL;
	if (!str[fd])
		return (NULL);
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		line = ft_substr(str[fd], 0, len + 1);
		tmp = ft_strdup(&(str[fd][len + 1]));
		free(str[fd]);
		str[fd] = tmp;
		//line[len] = '\n';
	}
	else
	{
		line = ft_strdup(str[fd]);
		ft_fdlinedel(str, fd);
	}
	return (line);
}

char	*get_next_line(const int fd)
{
	static char	*str[FILE_N];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	
	while (read(fd, buff, BUFFER_SIZE))
	{	
		if (!str[fd])
			str[fd] = ft_calloc(sizeof(char), BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
				break ;
	}
	return (addline(str, fd));
}
