/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:55:19 by jde-orma          #+#    #+#             */
/*   Updated: 2022/11/01 17:48:57 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		x;
	int		y;

	if (*to_find == '\0')
		return (str);
	x = 0;
	while (str[x])
	{
		y = 0;
		while (to_find[y] == str[x + y])
		{
			if (to_find[y + 1] == '\0')
			{
				return (str + x);
			}
			y++;
		}
		x++;
	}
	return (0);
}
