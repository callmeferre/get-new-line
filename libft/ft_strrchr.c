/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:28:54 by acastril          #+#    #+#             */
/*   Updated: 2021/07/29 15:27:27 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int	c)
{
	int		i;
	char	*str;
	char	find;

	str = (char *)s;
	find = (char)c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == find)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == find)
		return ((char *)str + i);
	return (0);
}
