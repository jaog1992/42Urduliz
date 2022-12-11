/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:57:33 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/10 11:09:40 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	unsigned char	k;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	k = 0;
	while (k < n)
	{
		if ((sc1 + k) != (sc2 + k))
		{
			return ((sc1 + k) - (sc2 + k));
		}
		k++;
	}
	return (0);
}
