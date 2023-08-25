/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:09:18 by jde-orma          #+#    #+#             */
/*   Updated: 2023/07/31 13:09:18 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_str_illegal_chr(char *s, Mapa *mapa1, int i)
{
	while (i >= 0)
	{
		if (!(s[i] == '1' || s[i] == '0' || s[i] == 'C' || s[i] == 'E' || \
			s[i] == 'P'))
			mapa1->error += print_error("Char different from '10CEP'\n");
		if (s[i] == 'E')
			mapa1->exit++;
		if (s[i] == 'P')
			mapa1->start++;
		if (s[i] == 'C')
			mapa1->collective++;
		i--;
	}
	return (0);
}

int	first_line_error_check(char *line, Mapa *mapa1, int error)
{
	error += ft_strrepeatchr(line, '1', 1);
	if (error == 1)
	{
		mapa1->error += print_error("All chars in first line must be == to 1\n");
		ft_printf_red(line);
	}
	mapa1->longitud_linea = ft_strlen(line) - 1;
	return (0);
}

int	last_line_error_check(char *line, Mapa *mapa1, int error)
{
	error += ft_strrepeatchr(line, '1', 0);
	if (error == 1)
	{
		mapa1->error += print_error("Char != 1 in last line");
		ft_printf_red(line);
	}
	if (mapa1->start > 1 || mapa1->start <= 0)
	{
		mapa1->error += print_error("Nº of 'Start'must be == 1, not ");
		ft_printf_red((int)mapa1->start);
	}
	if (mapa1->collective < 1)
	{
		mapa1->error += print_error("Nº of 'collectives' must be >= 1, not");
		ft_printf_red((int)mapa1->collective);
	}
	if (mapa1->exit > 1 || mapa1->exit <= 0)
	{
		mapa1->error += print_error("Nº of 'Exits' must be == 1, not ");
		ft_printf_red((int)mapa1->exit);
	}
	return (ft_strrepeatchr(line, '1', 0));
}

int	middle_line_error_check(char *line, Mapa *mapa1)
{
	if (mapa1->longitud_linea != ((size_t)ft_strlen(line) - 1))
	{
		mapa1->error += print_error("Line with wrong length -> ");
		ft_print_green(ft_itoa((int)ft_strlen(line)));
		ft_printf("!= ");
		ft_printf_red(ft_itoa((int)mapa1->longitud_linea));
	}
	if (line[0] != '1' || line[mapa1->longitud_linea - 1] != '1')
	{
		mapa1->error += print_error("Line start/end != '1'\n");
		ft_printf("%s\n", line);
	}
	return (ft_str_illegal_chr(line, mapa1, (ft_strlen(line) - 2)));
}

int	error_check(char *line, Mapa *mapa1, int i)
{
	if (i == 0)
		first_line_error_check(line, mapa1, 0);
	else if (i == (mapa1->numero_de_lineas - 1))
		last_line_error_check(line, mapa1, 0);
	else
		middle_line_error_check(line, mapa1);
	return (0);
}
