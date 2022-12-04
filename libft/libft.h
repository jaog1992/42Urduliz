/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 06:55:18 by jde-orma          #+#    #+#             */
/*   Updated: 2022/11/30 06:55:58 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>

int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(char c);
int	ft_isascii(char c);
int	ft_isprint(char c);
char	*ft_tolower(char *str);
char	*ft_toupper(char *str);
int	ft_strlen(char *c);
/*char	*ft_strchr(const char *s, int c);*/


#endif