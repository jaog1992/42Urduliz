/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:22:04 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/15 07:22:04 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;

    i = 0;
    if (!little)
        return (big);
    while (big[i] != '\0')
    {
        if (*(char *)(big + i) == *(char *) little)
        {
            if (ft_strncmp((big + i), little, len) == 0)
                return (little);
        }
        i++;
    }
    return (NULL);    
}
