/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:59:12 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/04 22:24:16 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* This function copies the first 'n' bytes of '*src' on the first 'n' bytes  */
/* of '*dest.                                                                 */
/*                                                                            */
/* The function works by initializing the pointer 's1' and 's2' to the start  */
/* of the memory blocks of 'dest' and 'src'.                                  */
/*                                                                            */
/* If 'dest' and 'src' are already equal 'dest' is returned.                  */
/*                                                                            */
/* Then the value of the 'i' position from 's2' is copied to the 'i' position */
/* of 's1'.                                                                   */
/*                                                                            */
/* ************************************************************************** */

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
