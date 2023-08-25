/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:22 by jde-orma          #+#    #+#             */
/*   Updated: 2023/08/07 18:19:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(char *s, char *extension)
{
	int	i;

	i = 0;
	while ((s[i + (ft_strlen(s) - 4)] != '\0') && i < 4)
	{
		if (extension[i] != s[i + (ft_strlen(s) - 4)])
		{
			print_error("File extension not valid\n");
			return ;
		}
		i++;
	}
	return ;
}

Mapa	*inicializar_mapa(Mapa *mapa1)
{
	mapa1 = (Mapa *)malloc(sizeof(Mapa));
	if (mapa1 == NULL)
	{
		print_error("Memory allocation for Mapa data type failed");
		return (mapa1);
	}
	mapa1->error = 0;
	mapa1->exit = 0;
	mapa1->start = 0;
	mapa1->collective = 0;
	mapa1->numero_movimientos = 0;
	mapa1->numero_de_lineas = 0;
	mapa1->longitud_linea = 0;
	return (mapa1);
}

int	argument_checker(int argc, char **argv)
{
	if (argc == 1)
		return (print_error("Please, insert one argument..."));
	if (argc > 2)
		print_error("More arguments than expected... First will be taken.");
	is_valid_map(argv[1], ".ber");
	return (0);
}

int	parse_file(Mapa *mapa1, char **ptr, int fd, char **argv)
{
	int	i;

	i = 0;
	mapa1 = inicializar_mapa(mapa1);
	numero_de_lineas(mapa1, argv[1]);
	ptr = (char **)malloc(sizeof(char *) * (mapa1->numero_de_lineas + 1));
	if (ptr == NULL)
		return (free_ptr(mapa1, ptr));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open the text file. Check the spelling\n");
		return (1);
	}
	while (i < mapa1->numero_de_lineas)
	{
		mapa1->line = get_next_line(fd);
		if (!mapa1->line)
			break ;
		ptr[i] = (char *)malloc(sizeof(char) * (ft_strlen(mapa1->line) + 1));
		ft_bzero(ptr[i], ft_strlen(mapa1->line));
		ft_memcpy(ptr[i], mapa1->line, ft_strlen(mapa1->line));
		i++;
	}
	i = 0;
	while (i <= (mapa1->numero_de_lineas - 1))
	{
		mapa1->error += error_check(ptr[i], mapa1, i);
		i++;
	}
	if (mapa1->error > 0)
		return (1);
	if (close(fd) == -1)
	{
		print_error("Failed to close the file.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		free_flag;
	Mapa	*mapa1;
	char	**ptr;

	mapa1 = NULL;
	ptr = NULL;
	if (argument_checker(argc, argv) == 1)
		return (0);
	free_flag = parse_file(mapa1, ptr, 0, argv);
	if (free_flag > 0)
		return (dbl_free_ptr(mapa1, ptr));
	return (0);
}
