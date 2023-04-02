/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:02:02 by jde-orma          #+#    #+#             */
/*   Updated: 2023/04/03 00:02:02 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

typedef struct	s_args
{
	unsigned int	i;
	char			*c;
}				t_args;

int	check_args_digit(int argc, char **argv);
int	check_isdigit(unsigned int i, char *c, void *args);
int error_checker(int argc, char **argv, int *s_a);
int push_swap(int argc, char **argv);