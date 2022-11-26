/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:07:56 by jde-orma          #+#    #+#             */
/*   Updated: 2022/10/31 08:08:41 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_bucles(int i, long nb)
{
	char	a[11];

	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	while ((nb / 10) > 0)
	{
		a[i] = (nb % 10) + 48;
		i++;
		nb = nb / 10;
	}
	if ((nb / 10) == 0)
	{
		a[i] = (nb % 10) + 48;
	}
	while (i >= 0)
	{
		ft_putchar(a[i]);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	long	h;

	h = nb;
	i = 0;
	ft_bucles(i, h);
}
