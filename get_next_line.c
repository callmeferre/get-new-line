/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:34:56 by acastril          #+#    #+#             */
/*   Updated: 2021/08/18 09:58:19 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*addline(char **str)
{
	int		len;
	char	*tmp;
	char *line;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = tmp;
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
	}
	return (line);
}

char	*output(char **str, size_t nchars)
{
	if (nchars > 0)
		return (addline(str));
	else
		return (NULL);
}

char	*get_next_line(const int fd)
{
	size_t		size;
	static char	*str[1];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	size = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, BUFFER_SIZE))
	{
		size++;
		buff[BUFFER_SIZE] = '\0';
		if (!*str)
			*str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(*str, buff);
			free(*str);
			*str = tmp;
		}
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (output(str, size));
}
