/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 06:55:18 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/22 17:03:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// FT_IS
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

//  FT_MATH
int		ft_pow(int base, int exponent);

//  FT_MEM
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_free(char	*str);

//  FT_PUT
int		ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putuint_fd(unsigned int n, int fd);
int		ft_puthex_x_fd(uintptr_t ptr, const char format, int fd);
int		ft_puthex_ux_fd(uintptr_t ptr, const char format, int fd);
int		ft_putptr_fd(uintptr_t ptr, const char format, int fd, int flag);
int		ft_printf(char const *str, ...);
int		ft_print_error(char *s);

//  FT_STR
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_nbrlen(int c);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strtol(char *c, int base);
char	*ft_get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_str(char *s1, char *s2, char *str);

//  FT_TO
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
char	*ft_uitoa(unsigned int n);

#endif
