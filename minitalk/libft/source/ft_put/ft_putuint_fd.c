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

#include "../../include/libft.h"

int	ft_putuint_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putuint_fd(n / 10, fd);
		if (i == -1)
			return (-1);
	}
	i += ft_putchar_fd(n % 10 + '0', 1);
	if (i == -1)
		return (-1);
	return (i);
}
