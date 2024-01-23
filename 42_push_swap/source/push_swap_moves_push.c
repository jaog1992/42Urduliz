/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:02 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:02 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

void	ft_pa(t_stack *stack, int mode)
{
	int	i;

	if (stack->size_b)
	{
		stack->a = resizeArray(stack->a, stack->size_a, stack->size_a + 1);
		stack->size_a++;
		if (stack->size_a > 1)
			i = stack->size_a - 1;
		else 
			i = 0;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i + 1 < stack->size_b)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b = resizeArray(stack->b, stack->size_b, stack->size_b - 1);
		stack->size_b--;
		if (mode == EXECUTE)
			ft_printf("pa\n");
	}
	else
	{
		if (mode == DO_NOTHING)
			ft_printf("Number can´t be pushed from empty stack [B]\n");
		return ;
	}
}

void	ft_pb(t_stack *stack, int mode)
{
	int	i;

	if (stack->size_a)
	{
		stack->b = resizeArray(stack->b, stack->size_b, stack->size_b + 1);
		stack->size_b++;
		if (stack->size_b > 1)
			i = stack->size_b - 1;
		else 
			i = 0;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a = resizeArray(stack->a, stack->size_a, stack->size_a - 1);
		stack->size_a--;
		if (mode == EXECUTE)
			ft_printf("pb\n");
	}
	else
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Stack A is empty.\n");
		return ;
	}
}
