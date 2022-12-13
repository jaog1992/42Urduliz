/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:57:33 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/14 00:44:52 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	if ((sc1 != sc2) && n != 0)
	{
		while (i < n)
		{
			if (*(sc1 + i) != *(sc2 + i))
				return ((sc2 + (char)i) - (sc1 + (char)i));
			i++;
		}
	}
	return (0);
}
