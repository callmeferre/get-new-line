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

/* La funcion doline diferencia entre linea con salto de linea y linea final.
** Si tiene salto de linea devuelve del string statico hasta el salto y
** si queda algo tras el salto de linea, esto se mantiene en el estatico.
** Si es fin de fichero, devuelve todo lo guardado y libera el string estatico.
*/

char	*doline(int len, char **str, const int fd)
{
	char	*tmp;
	char	*line;

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

/* la funcion output revisa si se ha acabado de leer el fichero
** en caso que sí devuelve nulo, si no averigua la longitud de la linea.
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

/* la funcion get_next_line lee el fichero hasta el primer salto de linea.
** Primero comprueba que exista un fichero y que este sea valido.
** Al leer el fichero, recogemos el numero de caracteres leidos,
** así al final de cada lectura terminamos el string buff en nulo.
** Si no existe aun el string estático se genera. Y se le va añadiendo
** lo que va leyendo mediante strjoin.
** Si encuentra un salto de linea, sale del bucle.
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
