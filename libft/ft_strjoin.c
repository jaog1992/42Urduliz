/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:04:12 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/15 08:04:12 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    calloc((s1 + ft_strlen(s1)), ft_strlen(s2));
    ft_memcpy(char *)(s1 + ft_strlen(s1)), (char *)s2, ft_strlen(s2);
    return (s1);
}