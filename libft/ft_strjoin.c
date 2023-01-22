/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:04:12 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 03:49:25 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)calloc(length, sizeof(char));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	ft_memcpy((char *)ptr, (char *)s1, ft_strlen(s1));
	ft_memcpy((char *)ptr + ft_strlen(s1), (char *)s2, ft_strlen(s2));
	return ((char *)ptr);
	free(ptr);
}
