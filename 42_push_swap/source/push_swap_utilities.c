/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:41:05 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:41:05 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

int* resizeArray(int *array, size_t oldSize, size_t newSize) 
{
    int *newArray;
    size_t elementsToCopy;

    newArray = (int*)malloc(newSize * sizeof(int));
    if (newArray == NULL)
	{
        ft_print_error("No se pudo asignar memoria.");
        exit(EXIT_FAILURE);
    }
    if (oldSize < newSize)
        elementsToCopy = oldSize;
    else
        elementsToCopy = newSize;
    ft_memcpy(newArray, array, elementsToCopy * sizeof(int));
    free(array);
    return newArray;
}

void	ft_error(t_stack *stack)
{
	write(2,"Error\n", 6);
	stack->error++;
}

int	ft_atoi2(char *str, t_stack *stack)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		ft_error(stack);
	return (num * neg);
}

int	ft_check_duplicates(int *stack, int len)
{
    int i;
    int j;

	i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (stack[i] == stack[j])
				return (EXIT_FAILURE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int	ft_check_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == ASCENDING)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (EXIT_FAILURE);
			i++;
		}
		return (EXIT_SUCCESS);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (EXIT_FAILURE);
			i++;
		}
		return (EXIT_SUCCESS);
	}
}
