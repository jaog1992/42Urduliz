/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:48 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/13 08:18:54 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dsti;

	i = 0;
	dsti = ft_strlen(dst);
	if (dsti < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && (i < (dstsize - ft_strlen(dst))))
		{
			dst[dsti] = src[i];
			i++;
			dsti++;
		}
		dst[dsti] = '\0';
	}
	return (ft_strlen(dst) + ft_strlen(src));
}
