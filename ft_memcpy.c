/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:59:12 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/02 21:10:20 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}