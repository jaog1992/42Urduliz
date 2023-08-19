/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:17:50 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/03 20:44:34 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_putstr_fd(num, fd);
	free(num);
	return (len);
}
