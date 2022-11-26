/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icobaner <icobaner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:55:58 by icobaner          #+#    #+#             */
/*   Updated: 2022/10/23 21:56:04 by icobaner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

/* Auxiliar functions */
int		ft_error(char *str);
int		ft_scan_string(char *str);
int		ft_scan_numcount(char *str);
int		ft_parse_arg(char *str, int square, int **mat);
void	ft_draw_mat(int **mat);
int		ft_test_35(int **a);
int		ft_test_empty(int final_mat);

/* Matrix functions */
void	ft_populate_mat(int **mat, int i, int j, int value);
int		**ft_init_mat(int square, int **mat);

/* Logic functions */
void	finding_fours1(int **a, int **f);
void	finding_fours2(int **a, int **f);
void	finding_threeud(int **a, int **f);
void	finding_threelg(int **a, int **f);
void	finding_oneup(int **a, int **f);
void	finding_onedown(int **a, int **f);
void	finding_oneleft(int **a, int **f);
void	finding_oneright(int **a, int **f);
void	finding_fourslr(int **a, int **f);
void	finding_foursupdown(int **a, int **f);
void	fill_column(int **f, int i, int j);
void	fill_row(int **f, int i, int j);

#endif