/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:24:41 by acastril          #+#    #+#             */
/*   Updated: 2021/07/30 10:26:15 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*str, const char	*to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (!to_find[j + 1])
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
