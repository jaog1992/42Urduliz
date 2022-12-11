/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:16:52 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/10 11:08:10 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*sc1;

	i = 0;
	sc1 = (unsigned char *)s;
	while (i < n)
	{
		if (*(sc1 + 1) == (unsigned char) c)
			return ((unsigned char *)sc1);
		i++;
	}
	return (NULL);
}
