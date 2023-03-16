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

# include <stdarg.h>
# include <unistd.h>

int		ft_printchararacter(char c, int fd);
int		ft_printstring(char *s, int fd);
int		ft_todecimal(int n);
int		ft_hex_len(unsigned long long ptr);
void	ft_put_hex(unsigned long long ptr, const char format);
int		ft_print_hexadecimal(unsigned long long ptr, const char format);
int		ft_nbrlen(int n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_var_type(va_list str, const char format);
int		ft_printf(char const *str, ...);

#endif