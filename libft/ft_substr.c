/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:53:55 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/15 07:53:55 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
   	char    *ptr;
    size_t  i;

    if (ft_strlen(s) < start)
        return (NULL);
    i = 0; 
   	ptr = calloc(start, len);
    ft_memcpy((char *)ptr, (char *)(s + start), len);
    return (ptr);
}