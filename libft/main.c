/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:11:25 by jde-orma          #+#    #+#             */
/*   Updated: 2022/11/30 13:04:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	main(int argc, char **argv)
{
	printf("El char introducido por linea de comandos es: %s \n", argv[argc - 1]);
	printf("	¿Es %s un char del alfabeto?: %d \n", argv[argc - 1], ft_isalpha(argv[argc - 1][0]));
	printf("	¿Es %s un char de tipo digito del cero al nueve?: %d \n", argv[argc - 1], ft_isdigit(argv[argc - 1][0]));
	printf("	¿Es %s un char alfanumerico?: %d \n", argv[argc - 1], ft_isalnum(argv[argc - 1][0]));
	printf("	¿Es %s un char del codigo ascii? %d \n", argv[argc - 1], ft_isascii(argv[argc - 1][0]));
	printf("	¿Es %s un char imprimible?: %d \n", argv[argc - 1], ft_isprint(argv[argc - 1][0]));
	printf("El string introducido por linea de comandos es: %s \n", argv[argc - 2]);
	printf("	- Tiene un total %d caracteres \n", ft_strlen(argv[argc - 2]));
	printf("	- Pasado a minuscula es: %s \n", ft_tolower(argv[argc - 2]));
	printf("	- Pasado a mayuscula es: %s \n", ft_toupper(argv[argc - 2]));
	printf("	- Su direccion de memoria es: %p y su valor es %c \n", argv[argc - 2], argv[argc - 2][0]);
	printf("	- Su direccion de memoria es: %p y su valor es %c \n", argv[argc - 2] + 1, argv[argc - 2][1]);
	printf("	- Su direccion de memoria es: %p y su valor es %c \n", argv[argc - 2] + 2, argv[argc - 2][2]);
	printf("	- Su direccion de memoria es: %p y su valor es %c \n", argv[argc - 2] + 3, argv[argc - 2][3]);
	printf("	- Su direccion de memoria es: %p y su valor es %c \n", argv[argc - 2] + 4, argv[argc - 2][4]);
	printf("	- La direccion de la primera ocurrencia de 'G' en %s es: %p \n", argv[argc - 2], ft_strchr(argv[argc - 2], 'G'));
	printf("	- La direccion de la ultima ocurrencia de 'G' en %s es: %p \n", argv[argc - 2], ft_strrchr(argv[argc - 2], 'G'));
	return (0);
}
