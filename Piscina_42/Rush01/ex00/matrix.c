/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:29:46 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:55:02 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**ft_init_mat(int square, int **mat)
{
	int	i;

	i = 0;
	mat = (int **)malloc(square * sizeof(int *));
	while (i < square)
	{
		mat[i] = (int *)malloc(square * sizeof(int));
		i++;
	}
	return (mat);
}

void	ft_populate_mat(int **mat, int i, int j, int value)
{
	mat[i][j] = value;
}

int	ft_test_empty(int final_mat)
{
	if (final_mat != 0)
		return (1);
	return (0);
}

int	ft_test_35(int **a)
{
	int	i;
	int	sum1;
	int	sum2;

	i = 0;
	while (i < 4)
	{
		sum1 = a[0][i] + a[1][i];
		sum2 = a[2][i] + a[3][i];
		if (!(sum1 >= 3 && sum1 <= 5))
			return (1);
		if (!(sum2 >= 3 && sum2 <= 5))
			return (1);
		i++;
	}
	return (0);
}
