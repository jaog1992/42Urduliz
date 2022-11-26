/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:14 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:53:34 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	finding_fours1(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[0][i] == 2 && a[1][i] == 3)
		{
			if (!(ft_test_empty(f[1][i])))
				f[1][i] = 4;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (a[0][i] == 3 && a[1][i] == 2)
		{
			if (!(ft_test_empty(f[2][i])))
				f[2][i] = 4;
		}
		i++;
	}
}

void	finding_fours2(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[2][i] == 2 && a[3][i] == 3)
		{
			if (!(ft_test_empty(f[i][1])))
				f[i][1] = 4;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (a[2][i] == 3 && a[1][i] == 2)
		{
			if (!(ft_test_empty(f[i][2])))
				f[i][2] = 4;
		}
		i++;
	}
}

void	finding_threeud(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[0][i] + a[1][i] == 3)
		{
			if (a[0][i] == 2)
			{
				if (!(ft_test_empty(f[0][i])))
					f[0][i] = 3;
			}
			else
			{
				if (!(ft_test_empty(f[3][i])))
					f[3][i] = 3;
			}
		}
		i++;
	}
}

void	finding_threelg(int **a, int **f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[2][i] + a[3][i] == 3)
		{
			if (a[2][i] == 2)
			{
				if (!(ft_test_empty(f[i][0])))
					f[i][0] = 3;
			}
			else
			{
				if (!(ft_test_empty(f[i][3])))
					f[i][3] = 3;
			}
		}
		i++;
	}
}
