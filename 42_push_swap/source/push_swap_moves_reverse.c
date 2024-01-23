/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:14 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:14 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

void	ft_rra(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	if (mode == EXECUTE)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	if (mode == EXECUTE)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
	if (mode == EXECUTE)
		ft_printf("rrr\n");
}
