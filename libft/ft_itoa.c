/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:33:32 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 00:33:32 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_reverse(int i, long num)
{
	char	*ptr;

    ptr = (char*)malloc(sizeof(char) * (12));
    ft_bzero(a, 12);
	if (num < 0)
	{
		num = num * -1;
		ptr[0] = '-';
        i++;
	}
	while ((num / 10) > 0)
	{
		ptr[i] = (num % 10) + 48;
		i++;
		num = num / 10;
	}
	if ((num / 10) == 0)
		ptr[i] = (num % 10) + 48;
    return(ptr);
}

char	*ft_reverted(int i, int count, char *ptr, char *ptr_reverse)
{
    if (ptr_reverse[0] = '-')
    {
        ptr[0] = ptr_reverse[0];
        count++;
    }
	while (count <= i)
	{
		ptr[count] = ptr_reverse[i - count];
	    count++;
	}
    return(ptr);
}

char	*ft_itoa(int n)
{
	long	h;
    char    *ptr;
    char    *ptr_reverse;

	h = n;
    ptr_reverse = ft_reverse(0, h);
    ptr = (char*)malloc(sizeof(char) * (ft_strlen(ptr_reverse) + 2));
    ft_bzero(ptr, (ft_strlen(ptr_reverse) + 2));
    if (!ptr)
        return (NULL);
	return (ft_reverted(ptr, ptr_reverse));
}