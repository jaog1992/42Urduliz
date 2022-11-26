/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:55:19 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:58:03 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	run(int **mat_in, int **mat_fin)
{
	finding_fourslr(mat_in, mat_fin);
	finding_foursupdown(mat_in, mat_fin);
	finding_fours1(mat_in, mat_fin);
	finding_fours2(mat_in, mat_fin);
	finding_threeud(mat_in, mat_fin);
	finding_threelg(mat_in, mat_fin);
	finding_oneup(mat_in, mat_fin);
	finding_onedown(mat_in, mat_fin);
	finding_oneleft(mat_in, mat_fin);
	finding_oneright(mat_in, mat_fin);
}

int	main(int argc, char *const *argv)
{
	int	square;
	int	**input_mat;
	int	**mat;

	input_mat = NULL;
	mat = NULL;
	square = 4;
	input_mat = ft_init_mat(square, input_mat);
	mat = ft_init_mat(square, mat);
	if (argc != 2)
		return (ft_error("(ERROR) Not enough arguments"));
	if (ft_parse_arg(*(argv + 1), square, input_mat))
		return (1);
	if (ft_test_35(input_mat))
		return (1);
	run(input_mat, mat);
	fill_column(mat, 0, 0);
	fill_row(mat, 0, 0);
	ft_draw_mat(mat);
	return (0);
}
