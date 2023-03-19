/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:02:42 by jde-orma          #+#    #+#             */
/*   Updated: 2023/03/17 11:02:42 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int		len;
	char	*ptr;

	len = 0;
	if (n == 0)
		len += ft_putchar_fd('0', fd);
	else
	{
		ptr = ft_uitoa(n);
		len += ft_putstr_fd(ptr, fd);
		free(ptr);
	}
	return (len);
}
