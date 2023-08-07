/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 06:55:06 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/29 06:55:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "so_long.h"

int	print_error(char *s)
{
	printf("\033[0;91mError\033[0;97m\n");
	printf("%s", s);
	return (1);
}

int	free_ptr(Mapa *mapa1, char **ptr)
{
	free(mapa1);
	free(ptr);
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)s;
	while (n--)
		*i++ = '\0';
}

int	ft_strrepeatchr(char *s, char c, int len)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(s) - 1 - len;
	while (i <= k)
	{
		if (s[i] != c)
			return (1);
		i++;
	}
	return (0);
}

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