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

#include "printf.h"
#include<unistd.h>

int	ft_var_type(va_list str, const char format)
{
	int	len;

	len = 0;
	while (format)
	{
		if (format == 'c')
			len += ft_printchararacter(va_arg(str, int), 1);
		if (format == 's')
			len += ft_printstring(va_arg(str, char *), 1);
		if (format == 'p')
			len += ft_print_hexa(va_arg(str, unsigned long long), format);
		if (format == 'd' || format == 'i')
			len += ft_todecimal(va_arg(str, int));
		if (format == 'u')
			len += ft_print_unsigned(va_arg(str, unsigned int));
		if (format == 'x' || format == 'X')
			len += ft_print_hexa(va_arg(str, int), format);
		if (format == '%')
			len += ft_printchararacter('%', 1);
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_var_type(ap, str[i + 1]);
		else
			write(1, str[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
