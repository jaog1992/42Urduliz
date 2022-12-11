/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:42:28 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/10 11:35:07 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	k;

	k = 0;
	if (!dst || !src)
		return (NULL);
	if (src < dst)
	{
		k = len -1;
		while (k >= 0)
		{
			*(char *)(dst + k) = *(char *)(src + k);
			k--;
		}
	}
	else
	{
		while (k < len)
		{
			*(char *)(dst + k) = *(char *)(src + k);
			k++;
		}
	}
	return (dst);
}
