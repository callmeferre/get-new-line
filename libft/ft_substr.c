/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:40:45 by acastril          #+#    #+#             */
/*   Updated: 2021/07/30 13:31:51 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
