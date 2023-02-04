/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:45:17 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/03 21:01:59 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* The ft_split function returns an array of substrings from the s string     */
/* using 'c' as the delimiter. If !s it returns a NULL value                  */
/*                                                                            */
/* The ft_count_substrings function counts the substrings and allocates the   */
/* memory fot the char**.                                                     */
/*                                                                            */
/* Given the char** the ft_alloc_substrings function allocates the memory for */
/* each substring and then copies each substring values to the given char*.   */
/* For that it runs through the string till the first non-occurrence of c.    */
/* Then it runs again through the string till the next ocurrence of c.        */
/* This limits the start and end of each of the substrings, which are then    */
/* given enough space on memory and copied using ft_memcpy, then adding the   */
/* null char at the end.                                                      */
/*                                                                            */
/* ************************************************************************** */

char	**ft_count_substrings(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**ptr;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	**ft_alloc_substrings(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	substring_id;

	i = 0;
	substring_id = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			ptr[substring_id] = (char *)malloc(sizeof(char) \
			* (i - start + 1));
			ft_memcpy(ptr[substring_id], s + start, i - start);
			ptr[substring_id][i - start] = '\0';
			substring_id++;
		}
	}
	ptr[substring_id] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_count_substrings(s, c);
	if (!ptr)
		return (NULL);
	ptr = ft_alloc_substrings(ptr, s, c);
	return (ptr);
}
