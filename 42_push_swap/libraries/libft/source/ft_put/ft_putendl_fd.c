/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 02:09:45 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 02:55:27 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	i += write(fd, s, ft_strlen(s));
	if (i == -1)
		return (i);
	flag += write(fd, "\n", 1);
	if (flag == -1)
		return (flag);
	else
		return (i + 1);
}
