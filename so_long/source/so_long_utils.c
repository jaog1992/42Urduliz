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

#include "so_long.h"

int	dbl_free_ptr(Mapa *mapa1, char **ptr)
{
	free(mapa1);
	free(ptr);
	return (1);
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
