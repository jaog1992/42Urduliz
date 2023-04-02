/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:31:37 by jde-orma          #+#    #+#             */
/*   Updated: 2023/04/02 23:31:37 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_args
{
	unsigned int	i;
	char			*c;
}				t_args;

int	check_args_digit(int argc, char **argv)
{
	int		i;
    int     flag;
	t_args	args;

	i = 1;
    flag = 0;
	while (i < argc)
	{
		args.i = i;
		args.c = argv[i];
		flag = ft_striteri(argv[i], &check_isdigit, &args);
        if (flag == 0)
            break;
		i++;
	}
    return (1);
}

int	check_isdigit(unsigned int i, char *c, void *args)
{
	t_args	*ptr_args;

	ptr_args = (t_args *)args;
	if (!isdigit(*c))
	{
		printf("El argumento %d contiene caracteres no numéricos.\n", ptr_args->i);
        return (0);
	}
    return (1);
}


int error_checker(int argc, char **argv, int *s_a)
{
    int i;
    int flag;

    i = 0;
    flag = check_args_digit;
    if (flag == 0)
        ´return (0);
    while (i < argc)
        s_a[i++] = atoi(argv[i + 2]);

    return (1);
}

int push_swap(int argc, char **argv)
{
    int *s_a;
    int *s_b;
    int flag;

    flag = 0;
    s_a = (int *) malloc (argc * sizeof(int));
    s_b = (int *) malloc (argc * sizeof(int));
    if (!s_a || !s_b)
        return(0);
    flag = error_checker(argc, argv, s_a);
    return (flag);
}