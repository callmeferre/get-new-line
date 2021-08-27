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

/* Doline function diferenciates between line with jump and last line.
** If it has a jump it returns the line until said jump and if there is anything
** left in that has been read but not return, keeps it in th static string.
** If it's end of file, returns everything and free the static string.
*/

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

/* Output function overlooks whether the file has ended, if
** so returns NULL, if not it gets the length of the line read.
*/

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

/* Get_next_line function reads the file until the first line jump.
** First checks if the file exist and is valid.
** While reading the file, it count the characters being read,
** so with each read it can end the buff string with a NULL character.
** If there's no static string, it creates one and fills it with
** the content that's being read with strjoin.
** It find a line jump, the loop ends.
*/

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
