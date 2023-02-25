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
#include "ft_printf.h"

int	ft_hex_len(unsigned	int ptr)
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

void	ft_put_hex(unsigned int ptr, const char format)
{
	if (ptr >= 16)
	{
		ft_put_hex(ptr / 16, format);
		ft_put_hex(ptr % 16, format);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((ptr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((ptr - 10 + 'A'), 1);
		}
	}
}

int	ft_x_or_X(unsigned int ptr, const char format)
{
	if (ptr == 0)
		return (write(1, "0", 1));
	else
    	ft_put_hex(ptr, format);
	return (ft_hex_len(ptr));
}