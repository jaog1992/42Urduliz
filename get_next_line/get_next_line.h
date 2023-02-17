/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:26:36 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/15 20:26:36 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/* ifndef means "If not defined" and it is used to know whether a macro has
been defined or not. Thus, if the code is compiled with the -D BUFFER_SIZE=XX 
the BUFFER_SIZE defined withtin the ifndef is not taken into account, as it
would have already been defined through the compilation flag.*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_alloc_new_line(char *line_str);
char	*ft_set_new_line_str(char *line_str);
char	*ft_read_line_to_string(int fd, char *line_str);
char	*get_next_line(int fd);

#endif