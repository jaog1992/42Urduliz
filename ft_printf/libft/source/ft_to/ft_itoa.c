/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 00:33:32 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/03 20:26:13 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* ft_itoa converts the integer value 'n' to its corresponding string         */
/* representation and returns a pointer to the newly created string.          */
/*                                                                            */
/* It uses ft_nbrlen to calculate the length of the string.                   */
/* The function first mallocs the memory needed for the string, and then      */
/* initializes it by storing each digit of the number, starting from the      */
/* rightmost digit and working towards the left.                              */
/*                                                                            */
/* If the number is negative, it stores a '-' sign at the beginning of the    */
/* string.                                                                    */
/*                                                                            */
/* Finally, the function returns the pointer 'ptr'.                           */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	num;
	size_t	len;

	len = ft_nbrlen(n);
	num = n;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	if (num == 0)
		ptr[0] = '0';
	while (num > 0)
	{
		ptr[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (ptr);
}
