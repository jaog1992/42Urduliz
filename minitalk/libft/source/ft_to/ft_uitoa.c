/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:33:21 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:33:21 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		len;

	len = ft_nbrlen((int) n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (n != 0)
	{
		ptr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}
