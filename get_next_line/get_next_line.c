/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:21:33 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/15 20:21:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/* char	*ft_read_till_newline_char(int fd, char *prev_line)                   */
/*                                                                            */
/* We join prev_line with the buffer till the newline char is found.          */
/* We protect the malloc.                                                     */
/* If the reading fails, we free the allocated memory and return a NULL       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_read_till_newline_char(int fd, char *prev_line)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(prev_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(prev_line);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		prev_line = ft_strjoin(prev_line, buff);
	}
	free(buff);
	return (prev_line);
}

/* ************************************************************************** */
/*                                                                            */
/* char	*ft_get_new_line(char *prev_line)                                     */
/*                                                                            */
/* We search the newline char on the previousley saved string.                */
/* We allocate the size of the array + 2 chars -> '\n' and '\0'.              */
/* We protect the malloc.													  */
/* We copy the string and then return it.                                     */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_new_line(char *prev_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!prev_line[i])
		return (NULL);
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
	{
		str[i] = prev_line[i];
		i++;
	}
	if (prev_line[i] == '\n')
	{
		str[i] = prev_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/* char	*ft_save_prev_line(char *prev_line)                                   */
/*                                                                            */
/* This function is meant for saving the characters read after \n for the     */
/* next call to get_next_line, as 'prev_line' is declared as a static char    */
/* in that function.                                                          */
/*                                                                            */
/* This is needed, as the buffer offset may be far advanced the previous      */
/* ocurrence of the newline character and we should be able to concatenate    */
/* the previously read chars that were not included on the 'next_line' string */
/*                                                                            */
/* We search for the ocurrence of the newline character on 'prev_line'.       */
/* We allocate enough memory for chars that were trimmed on the 'next_line'	  */
/* string.                                                                    */
/*                                                                            */
/* We copy they information to a new string and we free the allocated memory  */
/* for prev_line.                                                             */
/*                                                                            */
/* ************************************************************************** */

char	*ft_save_prev_line(char *prev_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	if (!prev_line[i])
	{
		free(prev_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(prev_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (prev_line[i])
		str[j++] = prev_line[i++];
	str[j] = '\0';
	free(prev_line);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/* char	*get_next_line(int fd)                                                */
/*                                                                            */
/* This function is meant for returning the next line to be read from a given */
/* file.                                                                      */
/*                                                                            */
/* For that, the buffer reads a set of BUFFER_SIZE chars each iteration till  */
/* till the first ocurrence of '\n' occurs. Then the red string is stored on  */
/* the 'prev_line' string.                                                    */
/*                                                                            */
/* Then, given the overlap that is likely to happen on the last buffer-read,  */
/* the string is 'split' in two:                                              */
/*    - The next line -> The line to be returned                              */
/*    - The previous line -> The spare string after the first ocurrence of    */
/*		'\n' on the string                                                    */
/* The 'prev_line' string needs to be static, as it must save it´s value      */
/* between function calls. Therefore, once 'next_line' is returned, we save	  */
/* the 'prev_line'                                                            */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*prev_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev_line = ft_read_till_newline_char(fd, prev_line);
	if (!prev_line)
		return (NULL);
	next_line = ft_get_new_line(prev_line);
	prev_line = ft_save_prev_line(prev_line);
	return (next_line);
}

/*int	main(void)
{
	char	*line;
	int		fd;

	fd = open("tests/text2.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("The read line is: %s", line);
	free(line);
	close(fd);
	return (0);
}*/