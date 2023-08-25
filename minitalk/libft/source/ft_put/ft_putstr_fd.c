/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:46:22 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/03 20:31:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (EXIT_FAILURE);
	if (!s)
		return (write(fd, "(null)", 6));
	i = write(fd, s, ft_strlen(s));
	if (i == -1)
		return (i);
	else
		return (ft_strlen(s));
}
