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

/* A string of the of the current buffer size is allocated on memory.
The file is read on Buffer-sized chunks till the \n character is found or the
EOF is reached. The read characters are been concatenated at the en of the str.
The buffer is then freed an the line is returned.
*/
char	*ft_read_to_line_str(int fd, char *line_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		line_str = ft_strjoin(line_str, buff);
	}
	free(buff);
	return (line_str);
}

/* It firstly joins the next line string with the previous one.
Then saves the new line on the "next_line" variable iwht ft_get_line
Erases the previously read line with ft_set_new_line_str.
Finally returns the next_line string*/
char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*line_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_str = ft_read_to_line_str(fd, line_str);
	if (!line_str)
		return (NULL);
	next_line = ft_get_line(line_str);
	line_str = ft_set_new_line_str(line_str);
	return (next_line);
}