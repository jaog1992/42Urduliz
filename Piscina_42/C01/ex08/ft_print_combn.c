/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:09:43 by jde-orma          #+#    #+#             */
/*   Updated: 2022/10/24 06:53:09 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_output(int n, int *sel, int pos)
{
	int	x;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	x = 0;
	while (x < n)
	{
		ft_putchar(sel[x] + '0');
		x++;
	}
}

void	ft_print_increment(int n, int *sel)
{
	int	x;
	int	max;

	x = n - 1;
	max = 9;
	while (sel[x] == max)
	{
		x--;
		max--;
	}
	sel[x] = sel[x] + 1;
	while (x < n)
	{
		sel[x + 1] = sel[x] + 1;
		x++;
	}
}

void	ft_print_combn(int num)
{
	int	sel[10];
	int	x;

	x = 0;
	while (x < num)
	{
		sel[x] = x;
		x++;
	}
	ft_put_output(num, sel, 0);
	while (sel[0] != 10 - num || sel[num - 1] != 9)
	{
		if (sel[num - 1] != 9)
		{
			sel[num - 1] = sel[num - 1] + 1;
		}
		else
		{
			ft_print_increment(num, sel);
		}
		ft_put_output(num, sel, 1);
	}
}
/*
int	main()
{
	ft_print_combn(3);
}
*/
