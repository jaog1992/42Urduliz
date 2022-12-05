/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:48 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/05 08:10:44 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	r;

	x = 0;
	y = ft_strlen(dst);
	r = size;
	if (size == 0)
		return (ft_strlen(src));
	if (size < y)
		r += y;
	else
		r += size;
	while (src[x] && y < r)
		dst[y++] = src[x++];
	dst[y] = '\0';
	return (r);
}
