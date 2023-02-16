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

int ft_printf(char const *, ...)
{
    int     i;
    char    **str;

    i = 0;
    str** = ft_split(*, '%');
    while (str[i])
    {
        if (str[i][0] == 'c')
            ft_putchar_fd(var_i[0], 1);
        if (str[i][0] == 's')
            ft_putstr_fd(var_i, 1);
        if (str[i][0] == 'p')
        //    ft_tohexadecimal(var_i, 1);
        if (str[i][0] == 'd')
        //    ft_todecimal(var_i, 1);
        if (str[i][0] == 'i')
        //    ft_tointeger(var_i, 1);
        if (str[i][0] == 'u')
        //    ft_tounsignedint(var_i, 1);
        if (str[i][0] == 'x')
        //    ft_striteri(ft_hexadecimal(var_i, 1), ft_tolower));
        if (str[i][0] == 'X')
        //    ft_striteri(ft_hexadecimal(var_i, 1), ft_toupper));
        if (str[i][0] == '%')
            ft_putchar_fd('%', 1);
        i++;
    }

}