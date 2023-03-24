/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:09:07 by jde-orma          #+#    #+#             */
/*   Updated: 2023/03/17 11:28:06 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* This function returns a pointer to the first occurrence of the chararcter  */
/* 'c' in the string 's'.                                                     */
/* If c == '\0' it returns the position of the null character on the string   */
/* If the character is not found, it returns a NULL.                          */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)(s + i));
	return (NULL);
}
