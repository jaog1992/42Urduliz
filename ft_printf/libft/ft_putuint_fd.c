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

#include "libft.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (n >= 10)
	{
		i += ft_putuint_fd(n / 10, fd);
	}
	flag = ft_putchar_fd(n % 10 + '0', 1);
	if (flag == -1)
		return (-1);
	else
		i++;
	return (i);
}
