/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:33:21 by jde-orma          #+#    #+#             */
/*   Updated: 2023/02/25 16:33:21 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	num;
	size_t	len;

	len = ft_nbrlen(n);
	num = n;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	if (num == 0)
		ptr[0] = '0';
	while (num > 0)
	{
		ptr[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (ptr);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	int		len;

	len = ft_nbrlen(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (n != 0)
	{
		ptr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*ptr;

	len = 0;
	if (n == 0)
		len += ft_printchararacter('0', 1);
	else
	{
		ptr = ft_uitoa(n);
		len += ft_printstring(ptr, 1);
		free(ptr);
	}
	return (len);
}
