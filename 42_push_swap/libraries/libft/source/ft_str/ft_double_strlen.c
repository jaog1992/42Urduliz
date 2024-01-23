/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:09:36 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/31 11:09:36 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_double_strlen(char **argv)
{
	size_t	i;

	i = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}
