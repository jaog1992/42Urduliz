/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:42:03 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:42:03 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* ft_puthex_fd is a function that translates and prints unsigned integers    */
/* to hexadecimal and prints the output to the set file descriptor.           */
/*                                                                            */
/* Note that a NULL pointer value should return (nil). Flag variable used     */
/* as a workaround to handle recursive iteration.                             */
/*                                                                            */
/* ************************************************************************** */

int	ft_puthex_fd(uintptr_t ptr, const char format, int fd, int flag)
{
	int	i;

	i = 0;
	if (format == 'p' && ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	if (format == 'X')
	{
		if (ptr >= 16)
			i += ft_puthex_fd(ptr / 16, format, fd, 0);
		i += ft_putchar_fd("0123456789ABCDEF"[ptr % 16], fd);
	}
	else if (format == 'x' || format == 'p')
	{
		if (format == 'p' && i == 0 && flag == 0)
			i += ft_putstr_fd("0x", 1);
		if (ptr >= 16)
			i += ft_puthex_fd(ptr / 16, format, fd, 1);
		i += ft_putchar_fd("0123456789abcdef"[ptr % 16], fd);
	}
	return (i);
}
