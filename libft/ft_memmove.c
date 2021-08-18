/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:10:10 by acastril          #+#    #+#             */
/*   Updated: 2021/07/29 14:33:11 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (dest == src || len == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			*(t_dest + i) = *(t_src + i);
			i++;
		}		
	}
	else
	{
		while (len--)
		{
			*(t_dest + len) = *(t_src + len);
		}
	}
	return (dest);
}
