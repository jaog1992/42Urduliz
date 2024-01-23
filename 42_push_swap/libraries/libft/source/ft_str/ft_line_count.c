/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_count  .c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:21:33 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/12 09:19:00 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_line_count(int *num_lines, char *str)
{
	char	*line;
	int		fd;

	line = NULL;
	num_lines = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			num_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
