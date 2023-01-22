/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:46:22 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 01:46:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return (NULL);
	write(fd, s, ft_strlen(s));
}