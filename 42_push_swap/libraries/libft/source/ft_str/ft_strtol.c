/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:36:51 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/18 13:36:51 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strtol(char *c, int base)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < (int)ft_strlen(c))
		num += ft_pow(base, (c[i] - 48));
	return (num);
}
