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

#include "libft.h"
#include "printf.h"

/*Modificar las funciones para que devuelvan el len de escritura!*/
int ft_var_type(va_list str, const char format)
{
    int len;

    len = 0;
    while (format)
    {
        if (format == 'c')
            len += ft_putchar_fd(va_arg(str, int), 1);
        if (format == 's')
            len += ft_putstr_fd(va_arg(str, char *), 1);
        if (format == 'p')
            len += ft_ptr_to_hexadecimal(va_arg(str, unsigned long long));
        if (format == 'd' || format == 'i')
            len += ft_todecimal(va_arg(str, int));
        if (format == 'u')
            len += ft_tounsignedint(va_arg(str, unsigned int));
        if (format == 'x' || format == 'X')
            len += ft_x_or_X(va_arg(str, int), format);
        if (format == '%')
            len += ft_putchar_fd('%', 1);
        i++;
    }
    return (len);
}

int ft_printf(char const *str, ...)
{
    size_t  i;
    size_t  len;
    va_list ap;

    i = 0;
    len = 0;
    va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_var_type(args, str[i + 1]);
		else
			ft_putchar_fd(str[i]);
		i++;
	}
    va_end(ap);
    return (len);
}