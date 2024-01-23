/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:42:28 by jde-orma          #+#    #+#             */
/*   Updated: 2023/04/03 19:20:35 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	const char	*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (const char *)src;
	if (!len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		dst_cpy[len] = src_cpy[len];
	return (dst);
}
