/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:28:38 by acastril          #+#    #+#             */
/*   Updated: 2021/08/06 10:53:55 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
