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

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned	long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_puthex_fd(unsigned long long ptr, int fd, const char format)
{
	if (ptr >= 16)
	{
		ft_puthex_fd(ptr / 16, fd, format);
		ft_puthex_fd(ptr % 16, fd, format);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), fd);
		else
		{
			if (format == 'X')
				ft_putchar_fd((ptr - 10 + 'A'), fd);
			else
				ft_putchar_fd((ptr - 10 + 'a'), fd);
		}
	}
}

int	ft_putptr_fd(unsigned long long ptr, int fd, const char format)
{
	if (ptr == 0 && format == 'p')
		return (ft_putstr_fd("(null)", fd));
	else if (ptr == 0 && format != 'p')
		return (ft_putchar_fd('0', fd));
	else
		ft_puthex_fd(ptr, fd, format);
	return (ft_hex_len(ptr));
}
