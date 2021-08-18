/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:29:14 by acastril          #+#    #+#             */
/*   Updated: 2021/07/29 14:33:16 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dest;
	unsigned char	*t_src;

	i = 0;
	if (!dest && !src)
		return (0);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	while (i++ < n)
		*t_dest++ = *t_src++;
	return (dest);
}
