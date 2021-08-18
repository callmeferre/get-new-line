/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastril <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:49:06 by acastril          #+#    #+#             */
/*   Updated: 2021/07/29 15:29:24 by acastril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int	c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
