/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:25:07 by jde-orma          #+#    #+#             */
/*   Updated: 2023/03/26 11:25:11 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(uintptr_t ptr, const char format, int fd, int flag)
{
	int	i;

	i = 0;
	if (format == 'X')
	{
		if (ptr >= 16)
			i += ft_putptr_fd(ptr / 16, format, fd, 0);
		if (ft_putchar_fd("0123456789ABCDEF"[ptr % 16], fd) != -1)
			i++;
		else
			return (-1);
	}
	else if (format == 'x' || format == 'p')
	{
		if (format == 'p' && i == 0 && flag == 0)
		{
			if (ft_putstr_fd("0x", 1) != -1)
				i += 2;
			else
				return (-1);
		}
		if (ptr >= 16)
			i += ft_putptr_fd(ptr / 16, format, fd, 1);
		if (ft_putchar_fd("0123456789abcdef"[ptr % 16], fd) != -1)
			i++;
		else
			return (-1);
	}
	return (i);
}
