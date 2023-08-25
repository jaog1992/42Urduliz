/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:38:07 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 03:18:02 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* ft_striteri is a function that iterates over each character in a string    */
/* and applies a provided function in the second argument to each character.  */
/* The specific function provided in the second argument is invoked with two  */
/* arguments: the index of the character in the string and the character      */
/* itself.                                                                    */
/*                                                                            */
/* EXAMPLE                                                                    */
/*                                                                            */
/* ft_striteri(str, to_upper);                                                */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
