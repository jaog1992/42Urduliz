/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:48 by jde-orma          #+#    #+#             */
/*   Updated: 2022/11/30 18:42:48 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	r;

	x = 0;
	y = 0;
	r = 0;
	while (dest[x])
		x++;
	while (src[r])
		r++;
	if (size <= x)
		r += size;
	else
		r += x;
	while (src[y] && x + 1 < size)
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (r);
}