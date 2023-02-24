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

char	*ft_read_prev_line(int fd, char *prev_line)
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

char	*ft_new_prev_line(char *prev_line)
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

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*prev_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev_line = ft_read_prev_line(fd, prev_line);
	if (!prev_line)
		return (NULL);
	next_line = ft_get_new_line(prev_line);
	prev_line = ft_new_prev_line(prev_line);
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