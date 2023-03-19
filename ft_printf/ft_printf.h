/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:54:19 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:54:19 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_hex_len(unsigned long long ptr);
void	ft_puthex_fd(unsigned long long ptr, int fd, const char format);
int		ft_putptr_fd(unsigned long long ptr, int fd, const char format);
char	*ft_uitoa(unsigned int n);
int		ft_putuint_fd(unsigned int n, int fd);
int		ft_var_type(va_list str, const char format);
int		ft_printf(char const *str, ...);
size_t	ft_strlen(const char *c);
int		ft_putnbr_fd(int n, int fd);
int		ft_nbrlen(int c);

#endif