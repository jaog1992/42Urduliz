/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:57:26 by jde-orma          #+#    #+#             */
/*   Updated: 2022/10/24 07:44:51 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_get_number(int a, int b, int i[])
{
	if (a >= 10)
	{
		i[0] = a / 10;
		i[1] = a - 10 * i[0];
	}
	else
	{
		i[0] = 0;
		i[1] = a;
	}
	if (b >= 10)
	{
		i[2] = b / 10;
		i[3] = b - 10 * i[2];
	}
	else
	{
		i[2] = 0;
		i[3] = b;
	}
}

void	ft_write(int a, int b)
{
	int	i[4];

	ft_get_number(a, b, i);
	ft_putchar(i[0] + 48);
	ft_putchar(i[1] + 48);
	ft_putchar(' ');
	ft_putchar(i[2] + 48);
	ft_putchar(i[3] + 48);
	if (a != 98 || b != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_write(a, b);
			b++;
		}
		a++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
