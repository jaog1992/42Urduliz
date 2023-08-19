/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:37:30 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/04 23:56:55 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* This function fills a block of memory (*b) of a given length, in bytes     */
/* (len) with a given value(c).                                               */
/*                                                                            */
/* The function works by initializing a pointer 'i' to the start of the       */
/* memory block 'b', and then repeteadly storing the value 'c' at the         */
/* location 'i', incrementing 'i' until 'len' iterations have been            */
/* performed.                                                                 */
/*                                                                            */
/* The function returns a pointer to the start of the memory block            */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;

	i = (unsigned char *)b;
	while (len--)
		*i++ = (unsigned char)c;
	return (b);
}
