/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:22 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:22 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

void	ft_ra(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	i = 0;
	tmp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	if (mode == EXECUTE)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (mode == DO_NOTHING)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	if (mode == EXECUTE)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *stack, int mode)
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
	i = 0;
	tmp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	i = 0;
	tmp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	if (mode == EXECUTE)
		ft_printf("rr\n");
}
