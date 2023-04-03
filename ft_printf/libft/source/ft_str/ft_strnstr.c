/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:22:04 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/02 22:32:57 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *) haystack);
	while (haystack[i] != '\0' && i + ft_strlen(needle) <= len)
	{
		if (!ft_strncmp((haystack + i), needle, ft_strlen(needle)))
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
