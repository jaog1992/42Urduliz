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

#include<unistd.h>

int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(char c);

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	int		c;
	char	A;
	char	B;
	char	C;

	A = argv[argc - 3][0];
	B = argv[argc - 2][0];
	C = argv[argc - 1][0];
	a = ft_isalpha(A) + 48;
	b = ft_isdigit(B) + 48;
	c = ft_isalnum(C) + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	return (0);
}
