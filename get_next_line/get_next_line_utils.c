/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:26:01 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/15 20:26:01 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* -- ft_strlen | ft_strchr | ft_strjoin --                                   */
/*                                                                            */
/* See libft project                                                          */
/*                                                                            */
/* -- ft_alloc_new_line --                                                    */
/*                                                                            */
/* The newly read line has been joined to the previous one. Thus, line_str    */
/* has 2 \n characters. once the first ocurrence of \n has been encountered   */
/* the start of the new line is found. Then the next characters can be copied */
/* to a newly declared string (str).                                          */
/*                                                                            */
/* -- get_next_line --                                                        */
/*                                                                            */
/* The line_str is searched till the first ocurrence of \n.                   */
/* If there is not such a character, the string is freed.                     */
/* If \n is encountered the correct size of str is allocated.                 */
/* The str is copied to the new str variable, and the old line_str is fred.   */
/* str is returned.                                                           */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *c)
{
	long unsigned int	a;

	a = 0;
	while (c[a] != '\0')
		a++;
	return (a);
}

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

char	*ft_strjoin(char *line_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line_str)
	{
		line_str = (char *)malloc(1 * sizeof(char));
		line_str[0] = '\0';
	}
	if (!line_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line_str)
		while (line_str[++i] != '\0')
			str[i] = line_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line_str) + ft_strlen(buff)] = '\0';
	free(line_str);
	return (str);
}

char	*ft_alloc_new_line(char *line_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_str)
		return (NULL);
	while (line_str[i] && line_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line_str[i] && line_str[i] != '\n')
	{
		str[i] = line_str[i];
		i++;
	}
	if (line_str[i] == '\n')
	{
		str[i] = line_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_set_new_line_str(char *line_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line_str[i] && line_str[i] != '\n')
		i++;
	if (!line_str[i])
	{
		free(line_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line_str[i])
		str[j++] = line_str[i++];
	str[j] = '\0';
	free(line_str);
	return (str);
}
