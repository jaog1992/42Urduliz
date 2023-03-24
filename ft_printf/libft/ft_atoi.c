/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:49:48 by jde-orma          #+#    #+#             */
/*   Updated: 2022/12/08 15:26:10 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* FUNCTIONALITY                                                              */
/*                                                                            */
/* The function ft_atoi converts the initial portion of the string pointed    */
/* to by str to int representation.                                           */
/*                                                                            */
/* It starts by initializing variables, then skips whitespaces in the input   */
/* string. Then, it handles the first optional sign and converts the number.  */
/*                                                                            */
/* It returns the converted int value.                                        */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	numb;
	int	flag;

	i = 0;
	flag = 0;
	sign = 1;
	numb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while ((str[i] == '+' || str[i] == '-') && flag == 0)
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
		flag = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i] - '0') + (numb * 10);
		i++;
	}
	return (numb * sign);
}
