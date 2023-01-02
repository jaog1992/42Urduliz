/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:19:55 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/03 00:47:20 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	while (set[i])
	{
		if (!ft_memchr(s1, set[i], ft_strlen(s1)))
			return ((char *)s1);
		else
		{	
			ptr = ft_memchr(s1, set[i], ft_strlen(s1));
			*ptr = '\0';
		}
		i++;
	}
	return ((char *)s1);
}
