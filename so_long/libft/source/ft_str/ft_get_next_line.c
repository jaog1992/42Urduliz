/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:21:33 by jde-orma          #+#    #+#             */
/*   Updated: 2023/03/12 09:19:00 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* ************************************************************************** */
/*                                                                            */
/* char	*ft_read_till_newline_char(int fd, char *prev_line)                   */
/*                                                                            */
/* Reads from a file descriptor until a newline character is encountered,     */
/* and joins the previous line with the newly read buffer data. Protects      */
/* against malloc errors and frees memory if the read fails.                  */
/*                                                                            */
/* 		fd: File Descriptor to read from                                      */
/* 		prev_line: the previously read line to be joined with the buffer data */
/*                                                                            */
/* 		returns: the joined line, or NULL if an error occurred                */
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
			return (ft_free(prev_line));
		}
		buff[read_bytes] = '\0';
		prev_line = ft_gnlstrjoin(prev_line, buff);
	}
	free(buff);
	return (prev_line);
}

/* ************************************************************************** */
/*                                                                            */
/* char	*ft_get_new_line(char *prev_line, int i)                              */
/*                                                                            */
/* Searches for the newline character on the previously saved string,         */
/* allocates enough memory to hold the line, copies the line to the new       */
/* string, and returns it. Protects against malloc errors.          		  */
/*                                                                            */
/* 		prev_line: the previously read line                                   */
/*                                                                            */
/*      returns: the new line, or NULL if an error occurred                   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_new_line(char *prev_line, int i)
{
	char	*str;

	if (!prev_line[i])
		return (NULL);
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	if (prev_line[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
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
/* Searches for the newline character on the previously read line, allocates  */
/* memory for the trimmed line, copies the trimmed line to a new string, and  */
/* frees the old string. Protects against malloc errors.                      */
/*                                                                            */
/* 		prev_line: the previously read line                                   */
/*                                                                            */
/* 		returns: the trimmed line, or NULL if an error occurred               */
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
		return (ft_free(prev_line));
	str = (char *)malloc(sizeof(char) * (ft_strlen(prev_line) - i + 1));
	if (!str)
		return (ft_free(prev_line));
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
/* Reads the next line from a file descriptor, joining any previously         */
/* unread buffer data from the previous call (static variable!).              */
/* Returns the next line and saves any remaining buffer data for the next     */
/* call. Protects against invalid file descriptor values or BUFFER_SIZE.      */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_next_line(int fd)
{
	char		*next_line;
	static char	*prev_line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev_line = ft_read_till_newline_char(fd, prev_line);
	if (!prev_line)
		return (ft_free(prev_line));
	next_line = ft_get_new_line(prev_line, 0);
	prev_line = ft_save_prev_line(prev_line);
	return (next_line);
}

//int	main(int argc, char **argv)
//{
//	int		fd;
//	char	*line;

//	if (argc == 2)
//	{
//		fd = open(argv[1], O_RDONLY);
//		if (fd == -1)
//		{
//			perror("Error while OPENING the text file");
//			return (1);
//		}
//		while (get_next_line(fd))
//		{
//			line = get_next_line(fd);
//			printf("%s\n", line);
//		}
//		free(line);
//		if (close(fd) == -1)
//		{
//			perror("Error while CLOSING the text file");
//			return (1);
//		}
//	}
//	else
//		printf("Set only 2 arguments: %s + filename\n", argv[0]);
//	return (0);
//}
