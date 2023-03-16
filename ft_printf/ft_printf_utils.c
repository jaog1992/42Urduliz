/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:16:09 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:16:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printchararacter(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_printstring(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_todecimal(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstring(num, 1);
	free(num);
	return (len);
}
