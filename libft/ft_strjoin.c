/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:04:12 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/03 19:01:10 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	length;

	if (!s1 && !s2)
	{
		ptr = (char *)malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)calloc(length, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy((char *)ptr, (char *)s1, ft_strlen(s1));
	ft_memcpy((char *)ptr + ft_strlen(s1), (char *)s2, ft_strlen(s2));
	ptr[length] = '\0';
	return (ptr);
}
