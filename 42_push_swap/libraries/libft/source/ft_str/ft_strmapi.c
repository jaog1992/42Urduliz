/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:31:38 by jde-orma          #+#    #+#             */
/*   Updated: 2023/01/22 03:07:10 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* ft_strmapi is a function that creates a new string by applying a provided  */
/* function (second argument ) to each character of the given string (s).     */
/*                                                                            */
/* (The difference with "ft_striteri" is that "ft_strmapi" returns a newly    */
/* allocated string with the transformed characters, while "ft_striteri"      */
/* modifies the original string in-place)                                     */
/*                                                                            */
/* The specific function provided in the second argument is invoked with two  */
/* arguments: the index of the character in the string and the character      */
/* itself.                                                                    */
/*                                                                            */
/* EXAMPLE                                                                    */
/*                                                                            */
/* ft_strmapi(str, to_upper);                                                 */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
