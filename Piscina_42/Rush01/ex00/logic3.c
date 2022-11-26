/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:12:02 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:54:09 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	finding_foursupdown(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[0][i] == 1)
			if (!(ft_test_empty(f[0][i])))
				f[0][i] = 4;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (a[1][i] == 1)
			if (!(ft_test_empty(f[3][i])))
				f[3][i] = 4;
		i++;
	}
}

void	finding_fourslr(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[2][i] == 1)
			if (!(ft_test_empty(f[i][0])))
				f[i][0] = 4;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (a[3][i] == 1)
			if (!(ft_test_empty(f[i][3])))
				f[i][3] = 4;
		i++;
	}
}

void	fill_row(int **f, int j, int i)
{
	int	a;
	int	resultado;
	int	*cero;

	i = 0;
	a = 0;
	while (i < 4)
	{		
		resultado = 0;
		j = 0;
		while (j < 4)
		{
			if (f[i][j] == 0)
			{
				a++;
				cero = &f[i][j];
			}
			resultado += f[i][j];
			j++;
		}
		if (a == 1)
			*cero = 10 - resultado;
		i++;
	}
}

void	fill_column(int **f, int j, int i)
{
	int	a;
	int	resultado;
	int	*cero;

	j = 0;
	a = 0;
	while (j < 4)
	{		
		resultado = 0;
		i = 0;
		while (i < 4)
		{
			if (f[i][j] == 0)
			{
				a++;
				cero = &f[i][j];
			}
			resultado += f[i][j];
			i++;
		}
		if (a == 1)
			*cero = 10 - resultado;
		j++;
	}
}
