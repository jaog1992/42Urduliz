/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:37:50 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:52:33 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	finding_oneup(int **a, int **f)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (a[0][i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				if (!(ft_test_empty(f[j][i])))
					f[j][i] = j +1;
				j++;
			}
		}
		i++;
	}
}

void	finding_onedown(int **a, int **f)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (a[1][i] == 4)
		{	
			j = 3;
			while (j >= 0)
			{
				if (!(ft_test_empty(f[j][i])))
					f[j][i] = 4 - j;
				j--;
			}
		}
		i++;
	}
}

void	finding_oneleft(int **a, int **f)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (a[2][i] == 4)
		{
			j = 0;
			while (j < 4)
			{
				if (!(ft_test_empty(f[i][j])))
					f[i][j] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	finding_oneright(int **a, int **f)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (a[3][i] == 4)
		{
			j = 3;
			while (j >= 0)
			{
				if (!(ft_test_empty(f[j][i])))
					f[j][i] = 4 - j;
				j--;
			}
		}
		i++;
	}
}
