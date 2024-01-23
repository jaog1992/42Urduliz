/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 6:22:32 by jde-orma           #+#    #+#             */
/*   Updated: 2023/10/31 6:22:32 by jde-orma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

t_stack *inicializar_stack()
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_print_error("Memory allocation for Stack data type failed\n");
		return (stack);
	}
	stack->error = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

int	stack_ini(t_stack *stack, int argc, char **argv)
{
	int			size;
	int			i;

	if (argc == 1)
		return (write(2,"Error\n", 6));
	i = 1;
	size = ft_double_strlen(argv);
	//ft_printf("ft_double_strlen executed correctly_ len: %d\n", size);
	stack->a = malloc((size) * sizeof(int));
	if (!stack->a)
		return (EXIT_FAILURE);
	stack->size_a = size - 1;
	while (i < size)
	{
		stack->a[i - 1] = ft_atoi2(argv[i], stack);
		if (stack->error > 0)
			return(EXIT_FAILURE);
		i++;
	}
	if (ft_check_duplicates(stack->a, size - 1) != 0)
	{
		ft_error(stack);
		return (EXIT_FAILURE);
	}
	ft_sort(stack, stack->size_a);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack 	*stack;
	//int			i;

	//i = 0;
	stack = inicializar_stack();
	if (!stack)
		return (EXIT_FAILURE);
	if (stack_ini(stack, argc, argv) != 0 || stack->error > 0)
	{
		exit (1);
		return (EXIT_FAILURE);
	}
	//while (i < stack->size_a)
	//{
	//	//ft_printf("i = %d and a[i] = %d\n", i, stack->a[i]);
	//	i++;
	//}
	//ft_printf("Stack ini executed correctly\n");
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
