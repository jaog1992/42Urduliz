/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:26:29 by jde-orma          #+#    #+#             */
/*   Updated: 2023/04/03 19:20:12 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* This function dynamically allocates memory using the 'malloc' function,    */
/* and then sets the first 'count * size' bytes of the memory block to zero.  */
/*                                                                            */
/* The function first sets a pointer 'ptr' to the result of allocating memory */
/* using 'malloc'. If the allocation fails, the function returns a NULL       */
/* pointer. Otherwise, it uses the 'ft_bzero' function to zero-out the        */
/* memory block.                                                              */
/*                                                                            */
/* Finally, the function returns the pointer 'ptr'.                           */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
