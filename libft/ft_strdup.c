/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:53:29 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/08 15:36:56 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s1)
{
	size_t		num;
	size_t		i;
	const char	*sc1;

	i = 0;
	num = ft_strlen(s1) + 1;
	sc1 = (const char *)ft_calloc(num, 1);
	if (!s1 || !sc1)
		return (NULL);
	while (s1[i])
	{
		sc1[i] = s1[i];
		i++;
	}
	return (ft_calloc(num, 1));
}
