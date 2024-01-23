/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:46:13 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/04 22:16:53 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* This function sets the first 'n' positions of a given pointer (*s) to the  */
/* NULL character '\0'.                                                       */
/*                                                                            */
/* The function works by initializin a pointer 'i' to the start of the memory */
/* block 's', and then repeatedly storing the value of '\0' a the location    */
/* 'i'.                                                                       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)s;
	while (n--)
		*i++ = '\0';
}
