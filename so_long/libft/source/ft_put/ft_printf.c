/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:21:01 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/16 19:21:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_var_type(va_list str, const char format)
{
	int	flag;

	flag = 0;
	if (format == 'c')
		flag += ft_putchar_fd(va_arg(str, int), 1);
	else if (format == 's')
		flag += ft_putstr_fd(va_arg(str, char *), 1);
	else if (format == 'p')
		flag += ft_putptr_fd(va_arg(str, uintptr_t), format, 1, 0);
	else if (format == 'd' || format == 'i')
		flag += ft_putnbr_fd(va_arg(str, int), 1);
	else if (format == 'u')
		flag += ft_putuint_fd(va_arg(str, unsigned int), 1);
	else if (format == 'x')
		flag += ft_puthex_x_fd(va_arg(str, unsigned int), format, 1);
	else if (format == 'X')
		flag += ft_puthex_ux_fd(va_arg(str, unsigned int), format, 1);
	else if (format == '%')
		flag += ft_putchar_fd('%', 1);
	return (flag);
}

static int	ft_printf_helper(va_list args, char const *str, int i, int flag)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			flag = ft_putchar_fd(str[i], 1);
		else
		{
			flag = ft_var_type(args, str[i + 1]);
			i++;
		}
		if (flag == -1)
			return (-1);
		else
			len += flag;
		i++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		len;
	va_list	args;

	if (!str)
		return (0);
	len = 0;
	va_start(args, str);
	len += ft_printf_helper(args, str, 0, 0);
	va_end(args);
	return (len);
}
