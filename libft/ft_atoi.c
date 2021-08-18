/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:31:00 by acastril          #+#    #+#             */
/*   Updated: 2021/08/04 16:34:53 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char	*str)
{
	int				value;
	unsigned int	n;

	value = 1;
	n = 0;
	while (*str && (ft_isspace(*str) == 1))
		str++;
	if (*str == '-')
		value *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		 n = (int)(*str - '0') + (n * 10);
		 if (n > 2147483647 && value == 1)
			 return (-1);
		 if (n > 2147483648 && value == -1)
			 return (0);
		 str++;
	}
	return (n * value);
}
