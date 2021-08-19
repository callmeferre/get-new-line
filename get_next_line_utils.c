/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:36:58 by acastril          #+#    #+#             */
/*   Updated: 2021/08/19 16:37:01 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *dest, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = dest;
	i = 0;
	while (i++ < len)
		*temp++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	ft_bzero(mem, size * count);
	return (mem);
}

size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (*str != 0)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(const char	*str)
{
	char	*n_str;
	size_t	i;

	i = 0;
	n_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!n_str)
		return (0);
	while (str[i])
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = 0;
	return (n_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!len)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2 [j++];
	str[i] = 0;
	return (str);
}

char	*ft_endofcpy(char *dest, char *src, size_t dstsize)
{
	if (dstsize != 0)
		*dest = '\0';
	while (*src != 0)
		src++;
	return (src);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	char	*c;
	size_t	r;

	c = (char *)src;
	r = dstsize;
	if (!src)
		return (0);
	if (dstsize != 0)
	{
		while (--r != 0)
		{
			*dest = *src;
			if (*dest == '\0')
				break ;
			dest++;
			src++;
		}
	}
	if (r == 0)
		src = ft_endofcpy(dest, (char *)src, dstsize);
	return (src - c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	char	*str;

	str = (char *)s;
	if (!s)
		return (0);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	s_len = ft_strlen(str + start);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	ft_strlcpy(substr, (str + start), len + 1);
	return (substr);
}