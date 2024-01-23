/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:33 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:33 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

void	ft_sa(t_stack *stack, int mode)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (mode == EXECUTE)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *stack, int mode)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (mode == EXECUTE)
		ft_printf("sb\n");
}

void	ft_ss(t_stack *stack, int mode)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (mode == EXECUTE)
		ft_printf("ss\n");
}
