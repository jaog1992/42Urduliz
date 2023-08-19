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

#include "../../include/libft.h"

int	ft_puthex_x_fd(uintptr_t ptr, const char format, int fd)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_puthex_x_fd(ptr / 16, format, fd);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar_fd("0123456789abcdef"[ptr % 16], fd) != -1)
		i++;
	else
		return (-1);
	return (i);
}

int	ft_puthex_ux_fd(uintptr_t ptr, const char format, int fd)
{
	int	i;

	i = 0;
	if (ptr >= 16)
	{
		i += ft_puthex_ux_fd(ptr / 16, format, fd);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar_fd("0123456789ABCDEF"[ptr % 16], fd) != -1)
		i++;
	else
		return (-1);
	return (i);
}

int	ft_putptr_fd(uintptr_t ptr, const char format, int fd, int flag)
{
	int	i;

	i = 0;
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
	return (i);
}

//int	ft_puthex_x_fd(uintptr_t ptr, const char format, int fd)
//{
//	char	hex[16];
//	int		i;
//
//	i = 0;
//	if (ptr == 0)
//		hex[i++] = '0';
//	else
//	{
//		while (ptr != 0)
//		{
//			hex[i++] = "0123456789abcdef"[ptr % 16];
//			ptr /= 16;
//		}
//	}
//	if (format == 'X')
//		ft_striteri(hex, &to_uppercase);
//	while (i-- > 0)
//	{
//		if (ft_putchar_fd(hex[i], fd) == -1)
//			return (-1);
//	}
//	return (i);
//}
