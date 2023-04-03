/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:57:33 by jde-orma          #+#    #+#             */
/*   Updated: 2023/04/03 19:20:23 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while ((sc1 || sc2) && i < n)
	{
		if (sc1[i] != sc2[i])
		{
			return ((sc1[i] + (unsigned char)i) \
				- (sc2[i] + (unsigned char)i));
		}
		i++;
	}
	return (0);
}
