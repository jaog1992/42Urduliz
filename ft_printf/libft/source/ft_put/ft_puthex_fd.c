/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_or_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:42:03 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:42:03 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(size_t ptr, const char format, int fd)
{
	int	i;

	i = 0;
	if (format == 'X')
	{
		if (ptr >= 16)
			i += ft_puthex_fd(ptr / 16, format, fd);
		i += ft_putchar_fd("0123456789ABCDEF"[ptr % 16], fd);
	}
	else if (format == 'x' || format == 'p')
	{
		if (ptr >= 16)
			i += ft_puthex_fd(ptr / 16, format, fd);
		i += ft_putchar_fd("0123456789abcdef"[ptr % 16], fd);
	}
	return (i);
}
