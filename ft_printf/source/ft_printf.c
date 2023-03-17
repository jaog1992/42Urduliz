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

#include "ft_printf.h"
#include "libft.h"

int	ft_var_type(va_list str, const char format)
{
	int	len;

	len = 0;
	while (format)
	{
		if (format == 'c')
			len += ft_putchar_fd(va_arg(str, int), 1);
		if (format == 's')
			len += ft_putstr_fd(va_arg(str, char *), 1);
		if (format == 'p')
			len += ft_putptr_fd(va_arg(str, unsigned long long), 1, format);
		if (format == 'd' || format == 'i')
			len += ft_putnbr_fd(va_arg(str, int), 1);
		if (format == 'u')
			len += ft_putuint_fd(va_arg(str, unsigned int), 1);
		if (format == 'x' || format == 'X')
			len += ft_putptr_fd(va_arg(str, unsigned long long), 1, format);
		if (format == '%')
			len += ft_putchar_fd('%', 1);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_var_type(args, str[i + 1]);
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
